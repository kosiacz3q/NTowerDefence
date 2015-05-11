#pragma once

#include <map>

template<class AssetHolder>
class GenericManager
{
public:
	
	void InsertAsset(const std::string id, AssetHolder assetHolder);
	AssetHolder getAsset(const std::string& id);

private:

	typedef std::map<std::string, AssetHolder> AssetsContainer;
	typedef std::pair<std::string, AssetHolder> PairIdAsset;

	AssetsContainer assetsContainer;
};

template<class AssetHolder>
void GenericManager<AssetHolder>::InsertAsset(const std::string id, AssetHolder assetHolder)
{
	if (assetsContainer.find(id) != assetsContainer.end())
		throw std::logic_error("Asset with id " + id + " already exists");

	assetsContainer.insert(
		PairIdAsset(
		id,
		assetHolder));
}

template<class AssetHolder>
AssetHolder GenericManager<AssetHolder>::getAsset(const std::string& id)
{
	auto result = assetsContainer.find(id);

	if (result == assetsContainer.end())
		throw std::logic_error("There is no asset with id " + id);

	return result->second;
}
