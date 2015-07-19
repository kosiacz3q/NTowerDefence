#pragma once

#include <map>

template<class AssetHolder>
class BaseGenericAssetsManager
{
private:
	typedef std::map<std::string, AssetHolder> AssetsContainer;
	typedef std::pair<std::string, AssetHolder> PairIdAsset;

public:

	//static_assert(std::is_same<AssetHolder, std::shared_ptr>::value);

	/*
	GenericAssetsManager()
		:assetsContainer(AssetsContainer())
	{

	}*/

	void InsertAsset(const std::string id, AssetHolder assetHolder);
	
	virtual AssetHolder getAsset(const std::string& id) = 0;

protected:

	AssetsContainer assetsContainer;
};

template<class AssetHolder>
void BaseGenericAssetsManager<AssetHolder>::InsertAsset(const std::string id, AssetHolder assetHolder)
{
	if (assetsContainer.find(id) != assetsContainer.end())
		throw std::logic_error("Asset with id " + id + " already exists");

	assetsContainer.insert(
		PairIdAsset(
		id,
		assetHolder));
}


