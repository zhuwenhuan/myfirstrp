#include<stdio.h>
//#include<stdlib.h>

struct mem_control_block{//内存控制块数据结构，用于管理所有的内存块
	int is_available;//标志此块是否可用 1-可 0-不可
	int size;//该快的大小
};

void *managed_memory_start;//指向堆底，堆中第一个内存块
void *last_valid_address;//指向堆顶，堆中最后一个内存块

void *mymalloc(size_t numbytes){
	void *current_location;//指向当前内存块
	struct mem_control_block *current_location_mcb;//保存当前内存块的内存控制结构
	void *memory_location;//保存满足条件的内存块的地址用于函数返回
	memory_location=NULL;
	numbytes=numbytes+sizeof(struct mem_control_block);//申请内存块的实际大小
	current_location=managed_memory_start;//利用全局变量得到堆中第一个内存块的地址

	while(current_location!=last_valid_address){//遍历堆中内存块
		current_location_mcb=(struct mem_control_block*)current_location;
		if(current_location_mcb->is_available){//判断当前内存块是否可用
			if(current_location_mcb->size>=numbytes){
				current_location_mcb->is_available=0;//满足条件的将其标为不可用
				memory_location=current_location;//得到该快地址，结束遍历
				break;
			}
		}
		current_location=current_location+current_location_mcb->size;//得到下一个内存块
	}
	if(!memory_location){//堆中已有内存块全都不满足条件
		if(sbrk(numbytes)==-1){
			return NULL;
		}
		memory_location=last_valid_address;
		last_valid_address=last_valid_address+numbytes;
		current_location_mcb=(struct mem_control_block*)memory_location;
		current_location_mcb->is_available=0;
		current_location_mcb->size=numbytes;
	}
	memory_location=memory_location+sizeof(struct mem_control_block);
	return memory_location;
}




void myfree(void *firstbyte)
{
	struct mem_control_block *mcb;
	mcb=firstbyte-sizeof(struct mem_control_block);
	mcb->is_available=1;
}
