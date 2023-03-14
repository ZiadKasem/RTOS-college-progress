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
  // disable systic 
  
    if(((ctr % ArrayOfStruct[0].periodicity ) == 0) && ctr >= 5){
  
      ArrayOfStruct[0].FunPtr();
  }
   if(((ctr % ArrayOfStruct[1].periodicity ) == 0) && ctr >= 10){
  
      ArrayOfStruct[1].FunPtr();
  }
   if(((ctr % ArrayOfStruct[2].periodicity ) == 0) && ctr >= 20){
  
      ArrayOfStruct[2].FunPtr();
  }
  // enable systic
  }
}