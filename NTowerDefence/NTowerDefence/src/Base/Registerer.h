#pragma once

#include <map>
#include <memory>

template <class T>
class Registerer
{
private:

	typedef std::map<std::string, T> Container;
	typedef std::shared_ptr<Container> ContainerPtr;

public:

	Registerer()
		:container(ContainerPtr(new Container()))
	{
	}

	void registerObject(std::string name, T object)
	{
		container->insert(std::make_pair(name, object));
	}

	void deregister(std::string name)
	{
		auto toRemove = container->find(name);

		if (toRemove != container->end())
		{
			container->erase(toRemove);
		}
	}

	void deregisterAll()
	{
		container->clear();
	}

	std::shared_ptr<const Container> getContainer()
	{
		return container;
	}

protected:
	ContainerPtr container;
};