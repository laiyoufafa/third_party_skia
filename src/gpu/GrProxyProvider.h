/*
 * Copyright 2018 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrProxyProvider_DEFINED
#define GrProxyProvider_DEFINED

#include "include/gpu/GrTypes.h"
#include "include/private/GrResourceKey.h"
#include "src/core/SkTDynamicHash.h"
#include "src/gpu/GrTextureProxy.h"

class GrImageContext;
class GrBackendRenderTarget;
struct GrVkDrawableInfo;
class SkBitmap;
class SkImage;

/*
 * A factory for creating GrSurfaceProxy-derived objects.
 */
class GrProxyProvider {
public:
    using UseAllocator = GrSurfaceProxy::UseAllocator;

    GrProxyProvider(GrImageContext*);

    ~GrProxyProvider();

    /*
     * Assigns a unique key to a proxy. The proxy will be findable via this key using
     * findProxyByUniqueKey(). It is an error if an existing proxy already has a key.
     */
    bool assignUniqueKeyToProxy(const GrUniqueKey&, GrTextureProxy*);

    /*
     * Sets the unique key of the provided proxy to the unique key of the surface. The surface must
     * have a valid unique key.
     */
    void adoptUniqueKeyFromSurface(GrTextureProxy* proxy, const GrSurface*);

    /*
     * Removes a unique key from a proxy. If the proxy has already been instantiated, it will
     * also remove the unique key from the target GrSurface.
     */
    void removeUniqueKeyFromProxy(GrTextureProxy*);

    /*
     * Finds a proxy by unique key.
     */
    sk_sp<GrTextureProxy> findProxyByUniqueKey(const GrUniqueKey&);

    /*
     * Finds a proxy by unique key or creates a new one that wraps a resource matching the unique
     * key.
     */
    sk_sp<GrTextureProxy> findOrCreateProxyByUniqueKey(const GrUniqueKey&,
                                                       UseAllocator = UseAllocator::kYes);

    /**
     * A helper that uses findOrCreateProxyByUniqueKey() to find a proxy and, if found, creates
     * a view for the found proxy using the passed in origin and color type. It is assumed that if
     * the proxy is renderable then it was created via a fallback code path so the fallback
     * color type will be used to create the view.
     */
    GrSurfaceProxyView findCachedProxyWithColorTypeFallback(const GrUniqueKey&,
                                                            GrSurfaceOrigin,
                                                            GrColorType,
                                                            int sampleCnt);

    /*
     * Creates a new texture proxy for the bitmap, optionally with mip levels generated by the cpu.
     * The bitmap is uploaded to the texture proxy assuming a kTopLeft_GrSurfaceOrigin.
     */
    sk_sp<GrTextureProxy> createProxyFromBitmap(const SkBitmap&,
                                                GrMipmapped,
                                                SkBackingFit,
                                                SkBudgeted);

    /*
     * Create a GrSurfaceProxy without any data.
     */
    sk_sp<GrTextureProxy> createProxy(const GrBackendFormat&,
                                      SkISize dimensions,
                                      GrRenderable,
                                      int renderTargetSampleCnt,
                                      GrMipmapped,
                                      SkBackingFit,
                                      SkBudgeted,
                                      GrProtected,
                                      GrInternalSurfaceFlags = GrInternalSurfaceFlags::kNone,
                                      UseAllocator useAllocator = UseAllocator::kYes);

    /*
     * Create a texture proxy from compressed texture data.
     */
    sk_sp<GrTextureProxy> createCompressedTextureProxy(SkISize dimensions,
                                                       SkBudgeted,
                                                       GrMipmapped,
                                                       GrProtected,
                                                       SkImage::CompressionType,
                                                       sk_sp<SkData> data);

    // These match the definitions in SkImage & GrTexture.h, for whence they came
    typedef void* ReleaseContext;
    typedef void (*ReleaseProc)(ReleaseContext);

    /*
     * Create a texture proxy that wraps a (non-renderable) backend texture. GrIOType must be
     * kRead or kRW.
     */
    sk_sp<GrTextureProxy> wrapBackendTexture(const GrBackendTexture&,
                                             GrWrapOwnership,
                                             GrWrapCacheable,
                                             GrIOType,
                                             sk_sp<GrRefCntedCallback> = nullptr);

    sk_sp<GrTextureProxy> wrapCompressedBackendTexture(const GrBackendTexture&,
                                                       GrWrapOwnership,
                                                       GrWrapCacheable,
                                                       sk_sp<GrRefCntedCallback> releaseHelper);

    /*
     * Create a texture proxy that wraps a backend texture and is both texture-able and renderable
     */
    sk_sp<GrTextureProxy> wrapRenderableBackendTexture(const GrBackendTexture&,
                                                       int sampleCnt,
                                                       GrWrapOwnership,
                                                       GrWrapCacheable,
                                                       sk_sp<GrRefCntedCallback> releaseHelper);

    /*
     * Create a render target proxy that wraps a backend render target
     */
    sk_sp<GrSurfaceProxy> wrapBackendRenderTarget(const GrBackendRenderTarget&,
                                                  sk_sp<GrRefCntedCallback> releaseHelper);

    sk_sp<GrRenderTargetProxy> wrapVulkanSecondaryCBAsRenderTarget(const SkImageInfo&,
                                                                   const GrVkDrawableInfo&);

    using LazyInstantiationKeyMode = GrSurfaceProxy::LazyInstantiationKeyMode;
    using LazySurfaceDesc = GrSurfaceProxy::LazySurfaceDesc;
    using LazyCallbackResult = GrSurfaceProxy::LazyCallbackResult;
    using LazyInstantiateCallback = GrSurfaceProxy::LazyInstantiateCallback;

    struct TextureInfo {
        GrMipmapped fMipmapped;
        GrTextureType fTextureType;
    };

    /**
     * Similar to createLazyProxy below, except narrowed to the use case of shared promise images
     * i.e. static so it doesn't have access to mutable state. Used by MakePromiseImageLazyProxy().
     */
    static sk_sp<GrTextureProxy> CreatePromiseProxy(GrContextThreadSafeProxy*,
                                                    LazyInstantiateCallback&&,
                                                    const GrBackendFormat&,
                                                    SkISize dimensions,
                                                    GrMipmapped);

    /**
     * Creates a texture proxy that will be instantiated by a user-supplied callback during flush.
     * The width and height must either both be greater than 0 or both less than or equal to zero. A
     * non-positive value is a signal that the width height are currently unknown. The texture will
     * not be renderable.
     *
     * When called, the callback must be able to cleanup any resources that it captured at creation.
     * It also must support being passed in a null GrResourceProvider. When this happens, the
     * callback should cleanup any resources it captured and return an empty sk_sp<GrTextureProxy>.
     */
    sk_sp<GrTextureProxy> createLazyProxy(LazyInstantiateCallback&&,
                                          const GrBackendFormat&,
                                          SkISize dimensions,
                                          GrMipmapped,
                                          GrMipmapStatus,
                                          GrInternalSurfaceFlags,
                                          SkBackingFit,
                                          SkBudgeted,
                                          GrProtected,
                                          UseAllocator);

    /** A null TextureInfo indicates a non-textureable render target. */
    sk_sp<GrRenderTargetProxy> createLazyRenderTargetProxy(LazyInstantiateCallback&&,
                                                           const GrBackendFormat&,
                                                           SkISize dimensions,
                                                           int renderTargetSampleCnt,
                                                           GrInternalSurfaceFlags,
                                                           const TextureInfo*,
                                                           GrMipmapStatus,
                                                           SkBackingFit,
                                                           SkBudgeted,
                                                           GrProtected,
                                                           bool wrapsVkSecondaryCB,
                                                           UseAllocator useAllocator);

    /**
     * Fully lazy proxies have unspecified width and height. Methods that rely on those values
     * (e.g., width, height, getBoundsRect) should be avoided.
     */
    static sk_sp<GrTextureProxy> MakeFullyLazyProxy(LazyInstantiateCallback&&,
                                                    const GrBackendFormat&,
                                                    GrRenderable,
                                                    int renderTargetSampleCnt,
                                                    GrProtected,
                                                    const GrCaps&,
                                                    UseAllocator);

    enum class InvalidateGPUResource : bool { kNo = false, kYes = true };

    /*
     * This method ensures that, if a proxy w/ the supplied unique key exists, it is removed from
     * the proxy provider's map and its unique key is removed. If 'invalidateSurface' is true, it
     * will independently ensure that the unique key is removed from any GrGpuResources that may
     * have it.
     *
     * If 'proxy' is provided (as an optimization to stop re-looking it up), its unique key must be
     * valid and match the provided unique key.
     *
     * This method is called if either the proxy attached to the unique key is being deleted
     * (in which case we don't want it cluttering up the hash table) or the client has indicated
     * that it will never refer to the unique key again.
     */
    void processInvalidUniqueKey(const GrUniqueKey&, GrTextureProxy*, InvalidateGPUResource);

    GrDDLProvider isDDLProvider() const;

    // TODO: remove these entry points - it is a bit sloppy to be getting context info from here
    uint32_t contextID() const;
    const GrCaps* caps() const;
    sk_sp<const GrCaps> refCaps() const;

    int numUniqueKeyProxies_TestOnly() const;

    // This is called on a DDL's proxyprovider when the DDL is finished. The uniquely keyed
    // proxies need to keep their unique key but cannot hold on to the proxy provider unique
    // pointer.
    void orphanAllUniqueKeys();
    // This is only used by GrContext::releaseResourcesAndAbandonContext()
    void removeAllUniqueKeys();

    /**
     * Does the proxy provider have access to a GrDirectContext? If so, proxies will be
     * instantiated immediately.
     */
    bool renderingDirectly() const;

#if GR_TEST_UTILS
    /**
     * Create a texture proxy that is backed by an instantiated GrSurface.
     */
    sk_sp<GrTextureProxy> testingOnly_createInstantiatedProxy(SkISize dimensions,
                                                              const GrBackendFormat& format,
                                                              GrRenderable renderable,
                                                              int renderTargetSampleCnt,
                                                              SkBackingFit fit,
                                                              SkBudgeted budgeted,
                                                              GrProtected isProtected);

    /** Version of above that picks the default format for the color type. */
    sk_sp<GrTextureProxy> testingOnly_createInstantiatedProxy(SkISize dimensions,
                                                              GrColorType colorType,
                                                              GrRenderable renderable,
                                                              int renderTargetSampleCnt,
                                                              SkBackingFit fit,
                                                              SkBudgeted budgeted,
                                                              GrProtected isProtected);

    sk_sp<GrTextureProxy> testingOnly_createWrapped(sk_sp<GrTexture>);
#endif

private:
    friend class GrAHardwareBufferImageGenerator; // for createWrapped
    friend class GrResourceProvider; // for createWrapped

    // processInvalidUniqueKey() with control over removing hash table entries,
    // which is not safe while iterating with foreach().
    enum class RemoveTableEntry { kNo, kYes };
    void processInvalidUniqueKeyImpl(const GrUniqueKey&, GrTextureProxy*,
                                     InvalidateGPUResource, RemoveTableEntry);

    bool isAbandoned() const;

    /*
     * Create an un-mipmapped texture proxy for the bitmap.
     */
    sk_sp<GrTextureProxy> createNonMippedProxyFromBitmap(const SkBitmap&, SkBackingFit, SkBudgeted);
    /*
     * Create an mipmapped texture proxy for the bitmap.
     */
    sk_sp<GrTextureProxy> createMippedProxyFromBitmap(const SkBitmap&,
                                                      SkBudgeted);

    sk_sp<GrTextureProxy> createWrapped(sk_sp<GrTexture> tex, UseAllocator useAllocator);
    template <class T> sk_sp<T> assignTagToProxy(sk_sp<T> proxy);

    struct UniquelyKeyedProxyHashTraits {
        static const GrUniqueKey& GetKey(const GrTextureProxy& p) { return p.getUniqueKey(); }

        static uint32_t Hash(const GrUniqueKey& key) { return key.hash(); }
    };
    typedef SkTDynamicHash<GrTextureProxy, GrUniqueKey, UniquelyKeyedProxyHashTraits> UniquelyKeyedProxyHash;

    // This holds the texture proxies that have unique keys. The resourceCache does not get a ref
    // on these proxies but they must send a message to the resourceCache when they are deleted.
    UniquelyKeyedProxyHash fUniquelyKeyedProxies;

    GrImageContext*        fImageContext;
};

#endif
