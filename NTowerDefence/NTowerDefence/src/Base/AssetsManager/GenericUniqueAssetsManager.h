#pragma once

template <class AssetHolder>
class GenericUniqueAssetsManager
	: public BaseGenericAssetsManager< AssetHolder >
{
public:
	AssetHolder getAsset(const std::string& id);
};

template<class AssetHolder>
AssetHolder GenericUniqueAssetsManager<AssetHolder, Asset>::getAsset(const std::string& id)
{
	auto result = assetsContainer.find(id);

	if (result == assetsContainer.end())
		throw std::logic_error("There is no asset with id " + id);

	return AssetHolder(*result->second);
}