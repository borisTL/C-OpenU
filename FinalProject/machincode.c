#include"assambler.h"

/*===================================================================================================================================================================*/
 struct MachineCode  {
unsigned short int are : 2;
unsigned short int addr_mode2 : 2;
unsigned short int addr_mode1 : 2;
unsigned short int opcode : 4;
unsigned short int op2 : 2;
unsigned short int op1 : 2; 
};
/*====================================================================================================================================================================*/
MachineCode* create_machine_code()
{
    MachineCode* mc = (MachineCode*)malloc(sizeof(MachineCode));
    mc->are = 0;
    mc->addr_mode2 = 0;
    mc->addr_mode1 = 0;
    mc->opcode = 0;
    mc->op2 = 0;
    mc->op1 = 0;
    return mc;
}
/*====================================================================================================================================================================*/
void free_machine_code(MachineCode *mc)
{
    if (mc != NULL)
    {
        free(mc);
    }
}
/*====================================================================================================================================================================*/
void fmachine_code_to_binary(MachineCode* mc, char* code_word) {

    memset(code_word, '0', SIZE_WORD);
    

    code_word[0] = (mc->op1 >> 1) & 1 ? '1' : '0';
    code_word[1] = mc->op1 & 1 ? '1' : '0';

    code_word[2] = (mc->op2 >> 1) & 1 ? '1' : '0';
    code_word[3] = mc->op2 & 1 ? '1' : '0';

    code_word[4] = (mc->opcode >> 3) & 1 ? '1' : '0';
    code_word[5] = (mc->opcode >> 2) & 1 ? '1' : '0';
    code_word[6] = (mc->opcode >> 1) & 1 ? '1' : '0';
    code_word[7] = mc->opcode & 1 ? '1' : '0';

    code_word[8] = (mc->addr_mode1 >> 1) & 1 ? '1' : '0';
    code_word[9] = mc->addr_mode1 & 1 ? '1' : '0';

    code_word[10] = (mc->addr_mode2 >> 1) & 1 ? '1' : '0';
    code_word[11] = mc->addr_mode2 & 1 ? '1' : '0';

    code_word[12] = (mc->are >> 1) & 1 ? '1' : '0';
    code_word[13] = mc->are & 1 ? '1' : '0';

    
}

/*====================================================================================================================================================================*/
void set_are(MachineCode* mc, unsigned short int are)
{mc->are = are;}
/*====================================================================================================================================================================*/
unsigned short int get_are(MachineCode* mc)
{return mc->are;}
/*====================================================================================================================================================================*/
void set_addr_mode2(MachineCode* mc, unsigned short int addr_mode2)
{mc->addr_mode2 = addr_mode2;}
/*====================================================================================================================================================================*/
unsigned short int get_addr_mode2(MachineCode* mc)
{return mc->addr_mode2;}
/*====================================================================================================================================================================*/
void set_machine_code_opcode(MachineCode* mc, unsigned short int opcode)
{mc->opcode = opcode;}
/*====================================================================================================================================================================*/
unsigned short int get_machine_code_opcode(MachineCode* mc)
{return mc->opcode;}
/*====================================================================================================================================================================*/
void set_addr_mode1(MachineCode* mc, unsigned short int addr_mode1)
{mc->addr_mode1 = addr_mode1;}
/*====================================================================================================================================================================*/
unsigned short int get_addr_mode1(MachineCode* mc)
{return mc->addr_mode1;}
/*====================================================================================================================================================================*/
void set_machine_code_op1(MachineCode* mc, unsigned short int op1)
{mc->op1 = op1;}
/*====================================================================================================================================================================*/
unsigned short int get_machine_code_op1(MachineCode* mc)
{return mc->op1;}
/*====================================================================================================================================================================*/
void set_machine_code_op2(MachineCode* mc, unsigned short int op2)
{mc->op2 = op2;}
/*====================================================================================================================================================================*/
unsigned short int get_machine_code_op2(MachineCode* mc) 
{return mc->op2;}
/*====================================================================================================================================================================*/




