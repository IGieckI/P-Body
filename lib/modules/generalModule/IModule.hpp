#pragma once

#include <Arduino.h>
#include <pins.h>
#include <config.h>

/**
 * @brief General definition of a module.
 * 
 */
class IModule
{
public:
    /**
     * @brief Construct a new IModule object
     * 
     * @param name Name of the module
     */
    IModule(const char* name) : moduleName(name) {}
    
    /**
     * @brief Module Initialization.
     *
     * @return true if the module was initialized successfully
     * @return false if the module failed to initialize
     */
    virtual bool init() = 0;
private:
    const char* moduleName;
};
