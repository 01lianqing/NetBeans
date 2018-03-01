
/*
binsort:数据和容器的属性之间的匹配
举个例子就是：
data{
	sign;
	others;
}DATA;
vector{
	sign;
	大容器;
}VECTOR;

现在的情况就是有一大堆大的数据。数据本身都有多个属性，
属性需要放到不同的容器中，而放入的判断就是容器上也有
一个和区分或唯一标志一类数据的标识，经过匹配可以实现
切割和分类

形象上看就是不同大小的黄豆，有自身体积和重量来落到对应的
筐子里面

这里的箱子排序是一种简化版的分类，首先分数之重复很多
而且类别较少，可以由简单的划分使得分数相同的数据进入
到同一个箱子里面，之后把箱子以一种顺序连起来

概要分析：
数据在链表里
把链表里面的数据一个一个的拆下来，匹配到对应的箱子
按一种顺序将箱子里面的数据以此取出来接到原来的链表
释放原来的箱子


数据结构：
typedef struct studentRecord{
	int score;
	string name;
	operator int ()const{
		return score;
	}
	int operator !=(const studentRecord& con){
		return (score != con.score);
	}
}RECORD;
方法1：
绑定分数和箱子map[score]就是对应分数的箱子
map<int,vector<int> > 
方法2：
同样是进过下标来匹配分数记录，但是注意到这里是连续的数据映射
vector<int> bin[range+1];
方法3：
手动写chain类 #只写需要的方法就OK#
chain<int> bin[]
方法4：
单单说映射的话，我可以采用
pair<int,vector<int> >
使用pair的sort方法。
可能算是按类分好之后，数据类别减少到一定的程度，直接sort

接口的考虑：
void binsort(vector<int> &,int type)
bool binsort(vector<int> &,int type)
void binsort(int array[],int size,vector<int> &ans,int type)

详细设计：

书上给了另一种方法：用了两组指针
currentPtr[]作为一个可移动的指针，依次向后移动
startPtr[]记录每一个箱子的起始节点

创建一个指向尾部的新的指针newFinal
依次遍历到每一个分数的startPtr[score],不空的话
连接到上一个的尾部 newFinal->next=startPtr[score]
指针newFinal被赋值为currentPrt[score]

*/
#ifndef BINSORT_H
#define BINSORT_H



#endif /* BINSORT_H */

