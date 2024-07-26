int variable_from_translation_unit1 = 15;
// no other translation unity is going to see this variable
// the linker will not see this in a global scope
// 
//
// try to mark symbols (variable/functions) static, unless i need them across multiple translation units
static int s_variable_from_translation_unit1 = 15;
static void function()
{
}

// static variables declared inside header files, when it is included, each translation unity that contains it,
// will have its own static version of the variable/function
// this variable in only visible/private to this cpp file/translation unity 
static int non_static_global_number = 7;