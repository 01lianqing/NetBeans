/*
概要设计：
求firstvt集合，求lastvt集合
建立算符优先的分析表
对给定的算式自底向上归纳得到起始符，返回true，否则返回false
                                                                                                                                                    
1* 求集合
insert_stack(){
  //如果为假的，转化为真，然后放入到stack
}

FIRSTVT(){
1*对所有的非终结符和终结符的组合，赋值为假 
  inti_Parray(){}
2*对每一个满足规则一的终结符和非终结符加入到栈中
    #001 if P->a OR P->Qa then insert_stack((P,a))
    ##01 P -> a 就是说P的产生式的第一个字符如果是终结符，加入
    ##02 P -> a 是说P的第一个是非终结符而第二个是终结符，加入
3*当栈不空时，重复着：
    #001 栈顶的元素记为(Q,a),弹出
    #002 对于每条P -> Q 做 insert_stack((P,a));
    ##0201 P->Q 意味着Q的firstvt集合应该加到P中

4*我们得到一个布尔数组，就是F[][],当其为真时，说明
终结符属于非终结符的firstvt集合
}

LASTVT(){

}
2*建表
##001 确定好大于、等于、小于 非别为 -1,0,1
// 想了想还是用字符吧 < > = #(error)
##002 比较的过程是拿行与列上的字符相比
create_table(){
  init_table();
  对每条产生式的后部做
     从i第一个字符到倒数第二个字符
      if(Xi 与Xi+1同时为终结符)  table[Xi][Xi+1]=0;
      if(i<n-2 && Xi 与Xi+2同时为终结符 && Xi+1为非终结符) table[Xi][Xi+2]=0;
      if(Xi 终结符 && Xi+1 不为终结符) {
        Xi+1的所有firstvt值大于Xi
      }
      if(Xi 非终结符 && Xi+1 为终结符) {
        Xi的所有lastvt值大于Xi
      }
}
3*判定
char a;
int deep_stack;
char stack_array[];
void check_process(){
  deep_stack=1;
  do{
  read(a);
  if(stack_array[deep_stack] 是终结符) deep_stack =k;
  else deep_stack = k-1;
  while(stack_array[deep_stack] > a){
    do{
      Q=stack_array[deep_stack];
      if(stack_array[deep_stack-1] 是终结符){
        deep_stack--;
      }else{
        deep_stack=deep_stack-2;
      }
    }while(stack_array[deep_stack] < Q);
    stack_array[j+1 ......k]归约为某个N
    deep_stack=j+1;
    stack_array[k]=N;
  }
  if(stack_array[j] <a && || stack_array[j] =a){
    deep_stack++;
    stack_array[deep_stack] =a;
  }else{
    error();
  }
}while(a!=#)

}



1、参考数据结构
char *VN=0,*VT=0;//非终结符和终结符数组
char firstvt[N][N],lastvt[N][N],table[N][N];
typedef struct   //符号对(P,a)
{
        char Vn;
        char Vt;
} VN_VT;
typedef struct  //栈
{
    VN_VT *top;
             VN_VT *bollow;
             int  size;
}stack;

2、根据文法求FIRSTVT集和LASTVT集
给定一个上下文无关文法，根据算法设计一个程序，求文法中每个非终结符的FirstVT 集和LastVT 集。
算符描述如下：
求 FirstVT 集的算法
PROCEDURE insert(P,a); 
IF not F[P,a] then   
begin  
        F[P,a] = true; //(P,a)进栈  
end;  
Procedure FirstVT; 
Begin 
for 对每个非终结符 P和终结符 a do 
   F[P,a] = false 
for 对每个形如 P		a…或 P→Qa…的产生式 do 
Insert(P,a) 
while stack  非空 
begin 
栈顶项出栈，记为(Q,a) 
for  对每条形如 P→Q…的产生式 do 
         insert(P,a) 
end; 
end.
同理，可构造计算LASTVT的算法。
3、构造算符优先分析表
依据文法和求出的相应FirstVT和 LastVT 集生成算符优先分析表。
算法描述如下：
for  每个形如 P->X1X2…Xn的产生式  do 
  for i =1 to n-1 do 
  begin 
        if Xi和Xi+1都是终结符 then  
           Xi   =   Xi+1 
        if i<= n-2, Xi和Xi+2 是终结符, 但Xi+1 为非终结符 then 
           Xi  = Xi+2 
        if Xi为终结符, Xi+1为非终结符 then   
             for FirstVT 中的每个元素 a do 
                  Xi  <  a ; 
        if Xi为非终结符, Xi+1为终结符 then 
             for LastVT 中的每个元素 a do 
                  a  >  Xi+1 ; 
  end
4、构造总控程序
         算法描述如下：
   stack S;
   k = 1;  //符号栈S的使用深度
   S[k] = ‘#’
   REPEAT
       把下一个输入符号读进a中；
       If S[k]   VT   then  j = k  else  j = k-1;
       While S[j] > a  do
           Begin
           Repeat
               Q = S[j];
               if  S[j-1]   VT  then  j = j-1  else   j = j-2
           until  S[j] < Q;
           把S[j+1]…S[k]归约为某个N，并输出归约为哪个符号；
           K = j+1;
           S[k] = N;
           end of while
       if S[j] < a  or  S[j] = a  then
           begin  k = k+1; S[k] = a      end
        else  error //调用出错诊察程序
    until a = ‘#’
5、对给定的表达式，给出准确与否的分析过程
6、给出表达式的计算结果。（本步骤可选作）

 */

/* 
typedef struct N_ending {
    char ch;
    int n;
} No_end;

typedef struct Ending {
    char ch;
    int n;
} End_char;

typedef struct ch_pair {
    No_end nch;
    End_char ech;
    ch_pair(No_end no,End_char end){
      nch=no;
      ech=end;
    }
}P_a;

建立映射
const No_end no[] = {
    {'E', 0},
    {'T', 1}, 
    {'F', 2},
    {'P', 3}
};

const End_char end[] = {
    {'i', 0},
    {'+', 1},
    {'*', 2},
    {'(', 3},
    {')', 4},
    {'^', 5},
    {'#', 6}
};
//也可以从文件流输入
string yuFa[4][2] = {
    "E+T", "T",
    "T*F", "F",
    "P^F", "P",
    "(E)", "i"
};

const int N_NUM=4;
const int E_NUM=7;
bool F[4][7];
bool L[4][7];
stack<P_a> Fvt_stack;
stack<P_a> Lvt_stack;

bool is_ending_char(char ch) {
    for (int i = 0; i < N_NUM; i++) {
        if (ch == no[i].ch) {
            return false;
        }
    }
    return true;
}

int find_number1(char ch) {
    if (!is_ending_char(ch)) {
        for (int i = 0; i < N_NUM; i++) {
            if (ch == no[i].ch) {
                return i;
            }
        }
    } else {
        for (int i = 0; i < E_NUM; i++) {
            if (ch == end[i].ch) {
                return i;
            }
        }
    }
}

char table[E_NUM][E_NUM];

insert_stack1(No_end no,End_char end){
  //如果为假的，转化为真，然后放入到stack
  int i=find_number1(no.ch);
  int j=find_number1(end.ch);
  if(F[i][j] == true){
        Fvt_stack.push(P_a(no.ch,end.ch));
  }
}

void init_Parray(){
        for(int i=0;i<N_NUM;i++)
                for(int j=0;j<E_NUM;j++){
                        F[i][j]=false;
                }
}

void FirstVt(){
        init_Parray();
        for(int i=0;i<N_NUM;i++)
                for(int j=0;j<2;j++){
                        string curr=yuFa[i][j];
                        char c_no=no[i];
                        char one=curr.at(0);
                        char two=curr.at(1);
                        if(is_ending_char(one)) insert_stack1(c_no,one);
                        if(!is_ending_char(one) && is_ending_char(two)) 
                                insert_stack1(c_no,two);
                }

        while(!Fvt_stack.empty()){
                P_a top_= Fvt_stack.top();Fvt_stack.pop();
                char no=top_.nch.ch;
                for(int i=0;i<N_NUM;i++)
                for(int j=0;j<2;j++){
                        string curr=yuFa[i][j];
                        char c_no=no[i];
                        char one=curr.at(0);
                        if(one == no) insert_stack1(c_no,one);
                }
        }
}


void init_table(){
     for(int i=0;i<E_NUM;i++)
        for(int j=0;j<E_NUM;j++){
                table[i][j]='#';
        }
}
void create_table(){
        init_table();
        for(int i=0;i<N_NUM;i++)
                for(int j=0;j<2;j++){
                        string curr=yuFa[i][j];
                        for(i=0;i<curr.size()-2;i++){
                                char x1=curr.at(i);
                                char x2=curr.at(i+1);
                                char x3=curr.at(i+2);
                                if(is_ending_char(x1) && is_ending_char(x2)){
                                        int x=find_number1(x1);
                                        int y=find_number1(x2);
                                        table[x][y] = '=';
                                }
                                if(is_ending_char(x1) && !is_ending_char(x2) &&is_ending_char(x3)){
                                        int x=find_number1(x1);
                                        int y=find_number1(x3);
                                        table[x][y] = '=';
                                }
                                if(is_ending_char(x1) && !is_ending_char(x2)){
                                        int n=find_number1(x2);
                                        for(int i=0;i<E_NUM;i++){
                                                if(F[n][i]){
                                                        int x=find_number1(x1);
                                                        int y=find_number1(no[i]);
                                                        table[x][y]='<';
                                                }
                                        }
                                }
                                if(!is_ending_char(x1) && is_ending_char(x2)){
                                        int n=find_number1(x1);
                                        for(int i=0;i<E_NUM;i++){
                                                if(L[n][i]){
                                                        int y=find_number1(x1);
                                                        int x=find_number1(end[i]);
                                                        table[x][y]='>';
                                                }
                                        }
                                }
                        }
                }
}

bool check_process(){
        //1 准备
        char a;
    int pos;
    char stack_array[];

    pos=1;
        do{
        a=getchar();// read(a);
        if(is_ending_char(stack_array[pos])) j =k;
        else j = k-1;
    

    int x=find_number1(stack_array[pos]);
    int y=find_number1(a);
        while(table[x][y] =='>'){
    do{
      char Q=stack_array[j];
      if(is_ending_char(stack_array[j-1])){
        j--;
      }else{
        j=j-2;
      }
      int x=find_number1(stack_array[j]);
      int y=find_number1(Q);
    }while(table[x][y] == '<');


    char N=come_down();
    //stack_array[j+1 ......pos]归约为某个N
    pos=j+1;
    stack_array[pos]=N;
        }

        int x=find_number1(stack_array[j]);
    int y=find_number1(a);
        if(table[x][y] == '<' && || table[x][y] == '='){
    pos++;
    stack_array[pos] =a;
        }else{
    error();
    // 少一个出错的检查函数
        }
        }while(a!=#);

}
 */

#ifndef FIRSTVT_H
#define FIRSTVT_H



#endif /* FIRSTVT_H */

