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
