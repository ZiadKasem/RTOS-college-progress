extern int ctr;
struct FunctionStruct  
{  
   void (*FunPtr)(void); // explain
   int periodicity;
};  
struct FunctionStruct ArrayOfStruct[3]={{0}};
static int funcNu =0;

void createfun(void (*PtrToFun)(void) , int period){
struct FunctionStruct intst;
  intst.FunPtr = PtrToFun;
  intst.periodicity=period;
  ArrayOfStruct[funcNu] = intst;
  funcNu++;
  
  
  
}


void schedular(){
  while(1){
  
    if((ArrayOfStruct[0].periodicity % ctr) == 0){
  
      ArrayOfStruct[0].FunPtr();
  }
    if((ArrayOfStruct[1].periodicity % ctr) ==0){
  
      ArrayOfStruct[1].FunPtr();
  }
   if((ArrayOfStruct[2].periodicity % ctr) ==0){
  
      ArrayOfStruct[2].FunPtr();
  }

  }
}