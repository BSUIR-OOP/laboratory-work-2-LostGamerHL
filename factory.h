#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include <QMap>

template <class Base>
class AbstractCreator
{
public:
	AbstractCreator() {}
	virtual ~AbstractCreator() {}
	virtual Base* create() const = 0;

private:
	AbstractCreator(const AbstractCreator&);
	AbstractCreator& operator = (const AbstractCreator&);
};


template <class C, class Base>
class Creator : public AbstractCreator<Base>
{
public:
	Creator() {}
	virtual ~Creator() {}

	Base * create() const
	{
		return new C();
	}
};

template <class Base>
class ObjectFactory
{
protected:
	typedef AbstractCreator<Base> AbstractFactory;
	typedef QMap<QString, AbstractFactory*> FactoryMap;

public:
	ObjectFactory() {}
	virtual ~ObjectFactory() {}

	Base * create(QString id) const
	{
		typename FactoryMap::const_iterator it = _map.find(id);
		if (it != _map.end())
			return (*it)->create();
		return NULL;
	}

	template <class C>
	void add(QString id)
	{
		registerClass(id, new Creator<C, Base>);
	}

	void remove(QString id)
	{
		typename FactoryMap::iterator it = _map.find(id);
		if (it != _map.end())
		{
			delete it->second;
			_map.erase(it);
		}
	}

	size_t size() const
	{
		return _map.size();
	}
protected:
	void registerClass(QString id, AbstractFactory * pAbstractFactory)
	{
		typename FactoryMap::iterator it = _map.find(id);
		if (it == _map.end())
			_map[id] = pAbstractFactory;
	}

private:
	ObjectFactory(const ObjectFactory&);
	ObjectFactory& operator = (const ObjectFactory&);

	FactoryMap _map;
};

#endif
