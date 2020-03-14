
#ifndef ClipLayer_HPP
#define ClipLayer_HPP

#include <plugin/plugin.hpp>

namespace Plugin {
	class ClipLayer : public TRTPlugin {
	public:
		//���ò��������ͨ���ִ꣬�в������������ͬʱִ��ģʽƥ�����֣�������ÿ�����������ģʽƥ��
		//��ƥ�䷽���õ���ccutil::patternMatch��������������
		SETUP_PLUGIN(ClipLayer, "clip*");

		virtual std::shared_ptr<LayerConfig> config(const std::string& layerName) override;

		//������ֻ��һ������������shape��������0��shape����˷���input0��shape
		virtual nvinfer1::Dims outputDims(int index, const nvinfer1::Dims* inputDims, int nbInputDims);

		//ִ�й���
		virtual int enqueue(const std::vector<Plugin::GTensor>& inputs, std::vector<Plugin::GTensor>& outputs, const std::vector<GTensor>& weights, void* workspace, cudaStream_t stream) override;
	};
}

#endif //ClipLayer_HPP