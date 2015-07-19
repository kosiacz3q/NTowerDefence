#pragma once

#include "BaseGenericAssetsManager.h"

template <class AssetHolder>
class GenericSharedAssetsManager
	: public BaseGenericAssetsManager< AssetHolder >
{
public:

	AssetHolder getAsset(const std::string& id);
};

template<class AssetHolder>
AssetHolder GenericSharedAssetsManager<AssetHolder>::getAsset(const std::string& id)
{
	auto result = assetsContainer.find(id);

	if (result == assetsContainer.end())
		throw std::logic_error("There is no asset with id " + id);

	return result->second;
}