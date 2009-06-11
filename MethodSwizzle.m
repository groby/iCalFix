#include <objc/objc-class.h>

#include "MethodSwizzle.h"

/**
 * Swizzle to selectors on a class
 */
void MethodSwizzle(Class aClass, SEL orig_sel, SEL alt_sel)
{
    if( aClass == nil ) 
        return;
    
    Method orig_method = nil, alt_method = nil;
    
    // First, look for the methods
    orig_method = class_getInstanceMethod(aClass, orig_sel);
    alt_method = class_getInstanceMethod(aClass, alt_sel);
    
    // If both are found, swizzle them
    if ((orig_method != nil) && (alt_method != nil))
    {
        char *temp1;
        IMP temp2;
        
        temp1 = orig_method->method_types;
        orig_method->method_types = alt_method->method_types;
         
        temp2 = orig_method->method_imp;
        orig_method->method_imp = alt_method->method_imp;
        alt_method->method_imp = temp2;
    }
}




