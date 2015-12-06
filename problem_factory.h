//
//  problem_factory.h
//  Problem factory
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-09-09.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#ifndef problem_factory_h
#define problem_factory_h





#include <map>
#include <string>

using namespace std;





template <class T> void *constructor()
{
    return (void *)new T();
}





struct problem_factory
{
    typedef void *(*constructor_t)();
    typedef map<string, constructor_t> map_type;
    map_type m_classes;
    
    template <class T>
    void register_class(string const& n)
    {
        m_classes.insert(make_pair(n, &constructor<T>));
    }
    
    void *construct(string const& n)
    {
        map_type::iterator i = m_classes.find(n);
        
        if (i == m_classes.end()) {
            return 0;
        }
        
        return i->second();
    }
};

problem_factory p_factory;

#define PROBLEM_FACTORY_REGISTER_CLASS(n) p_factory.register_class<n>(#n)
#define PROBLEM_FACTORY_INSTANTIATE_CLASS(n) (problem_base *)p_factory.construct(n)





#endif /* problem_factory_h */




