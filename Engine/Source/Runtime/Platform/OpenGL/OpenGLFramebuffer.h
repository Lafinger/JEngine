#ifndef OPENGLFRAMEBUFFER_H
#define OPENGLFRAMEBUFFER_H

#include "Runtime/Application/Renderer/Framebuffer.h"

namespace JEngine
{
    class OpenGLFramebuffer : public Framebuffer
    {
        friend class OpenGLPostProcessing;
    public:
        OpenGLFramebuffer(const FramebufferSpecification& spec);
        virtual ~OpenGLFramebuffer();

        void Invalidate();

        virtual void Bind() override;
        virtual void Unbind() override;
        virtual void BindReadFramebuffer() override;
        virtual void BindDrawFramebuffer() override;

        virtual void Resize(uint32_t width, uint32_t height) override;
		virtual int ReadPixel(uint32_t attachmentIndex, int x, int y) override;

		virtual void ClearAttachment(uint32_t attachmentIndex, int value) override;

        virtual uint32_t GetColorAttachmentRendererID(uint32_t index = 0) const override { JENGINE_CORE_ASSERT(index < mColorAttachments.size()); return mColorAttachments[index]; }
        virtual uint32_t GetDepthAttachmentRendererID() const override { return mDepthAttachment; }

        virtual const FramebufferSpecification& GetSpecification() const override { return mSpecification; }

        virtual void FramebufferTexture2D(uint32_t cubemapIndex, uint32_t cubemapID, uint32_t slot = 0) override;

        virtual Ref<class Texture3D> GetDepthTex3D() const override; // have bugs
        virtual void BindDepthTex3D(uint32_t slot) override;
        virtual void UnBindDepthTex3D(uint32_t slot) override;
    private:
        uint32_t mRendererID = 0;
        FramebufferSpecification mSpecification;

		std::vector<FramebufferTextureSpecification> mColorAttachmentSpecifications;
		FramebufferTextureSpecification mDepthAttachmentSpecification = FramebufferTextureFormat::None;

		std::vector<uint32_t> mColorAttachments;
		uint32_t mDepthAttachment = 0;
    };

}


#endif //!OPENGLFRAMEBUFFER_H
