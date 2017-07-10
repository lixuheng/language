#include <stdio.h>
#include <string.h>
#include <Windows.h>
typedef struct {
	char sno[20];
	char name[20];
	float chinese;
	float math;
	float english;
	float avg;
	float sum;
}Stu,*pStu;
typedef struct{
	int allStu;
	float chinese_sum;
	float math_sum;
	float english_sum;
	float chinese_avg;
	float math_avg;
	float english_avg;
	float chinese_max;
	float math_max;
	float english_max;
	float chinese_min;
	float math_min;
	float english_min;
}Count;
typedef struct{
	pStu stus;
	Count count;
}Class;
void init(pStu p_stu);
void menu();
void input(Class * pClass);
void calOneStuSum(pStu p_stu);
void calOneStuAvg(pStu p_stu);
void calStusSum(Class * pClass);
void calStusAvg(Class * pClass);
void calStusMax(Class * pClass);
void calStusMin(Class * pClass);
void sort(Class * pClass);
pStu find(Class * pClass,char *sno);
void printHead();
void printStu(Stu *p_stu);
void printStus(Class * pClass);
void printCount(Count count);
int main(){
	Class banji;
	int i=0,j=0,over = 1;
	printf("������༶����:");
	scanf("%d",&banji.count.allStu);
	banji.stus = (pStu)malloc(sizeof(Stu)*banji.count.allStu);
	for(;i<banji.count.allStu;i++){
		init(&banji.stus[i]);
	}
	menu();
	while(over){
		int k = 0;
		char sno[20];
		pStu cur = NULL;

		printf("\n���������ѡ��");
		scanf("%d",&k);

		switch(k){
		case 1:
			input(&banji);
			for(i=0;i<banji.count.allStu;i++){
				calOneStuSum(&banji.stus[i]);
				calOneStuAvg(&banji.stus[i]);
			}
			calStusAvg(&banji);
			calStusMax(&banji);
			calStusMin(&banji);
			system("cls");
			menu();
			break;
		case 2:
			printf("\n������Ҫ���ҵ�ѧ�ţ�");
			scanf("%s",sno);
			cur = find(&banji,sno);
			printHead();
			printStu(cur);
			break;
		case 3:
			printHead();
			printStus(&banji);
			break;
		case 4:
			sort(&banji);
			break;
		case 5:
			printCount(banji.count);
			break;
		case 6:
			system("cls");
			menu();
			break;
		case 7:
			over =0;
			break;
		default:
			over =0;
			break;
		}
	}
	free(banji.stus);
	return 0;
}
void init(pStu p_stu){
	p_stu->avg = 0;
	p_stu->sum = 0 ;
	p_stu->chinese = 0;
	p_stu->english = 0;
	p_stu->math = 0;
}
void menu(){
	printf("\t------------menu----------\n");
	printf("\t|1.¼��ѧ����Ϣ\n");
	printf("\t|2.�鿴����ѧ����Ϣ\n");
	printf("\t|3.�鿴����ѧ����Ϣ\n");
	printf("\t|4.���򲢲鿴����ѧ����Ϣ\n");
	printf("\t|5.�鿴�༶ͳ����Ϣ\n");
	printf("\t|6.����\n");
	printf("\t|7.�˳�ϵͳ\n");
}
void input(Class * pClass){
	int i =0 ;
	for(;i<pClass->count.allStu ;i++){
		printf("�������%d��ѧ����Ϣ\n",(i+1));
		printf("ѧ�ţ�");
		scanf("%s",pClass->stus[i].sno);
		printf("������");
		scanf("%s",pClass->stus[i].name);
		printf("���ĳɼ���");
		scanf("%f",&pClass->stus[i].chinese);
		printf("��ѧ�ɼ���");
		scanf("%f",&pClass->stus[i].math);
		printf("Ӣ��ɼ���");
		scanf("%f",&pClass->stus[i].english);
	}
}
void calOneStuSum(pStu p_stu){
	p_stu->sum = p_stu->chinese+p_stu->english+p_stu->math;
}
void calOneStuAvg(pStu p_stu){
	calOneStuSum(p_stu);
	p_stu->avg = p_stu->sum/3.0;
}
void calStusSum(Class * pClass){
	int i=0;
	pClass->count.chinese_sum= 0;
	pClass->count.math_sum= 0;
	pClass->count.english_sum= 0;
	for(;i<pClass->count.allStu;i++){
		pClass->count.chinese_sum+=pClass->stus[i].chinese;
		pClass->count.math_sum+=pClass->stus[i].math;
		pClass->count.english_sum+=pClass->stus[i].english;
	}
}
void calStusAvg(Class * pClass){
	calStusSum(pClass);
	pClass->count.chinese_avg=pClass->count.chinese_sum/pClass->count.allStu;
	pClass->count.math_avg=pClass->count.math_sum/pClass->count.allStu;
	pClass->count.english_avg=pClass->count.english_sum/pClass->count.allStu;
}
void calStusMax(Class * pClass){
	int i=0;
	pClass->count.chinese_max= 0;
	pClass->count.math_max= 0;
	pClass->count.english_max= 0;
	for(;i<pClass->count.allStu;i++){
		if(pClass->count.chinese_max<pClass->stus[i].chinese){
			pClass->count.chinese_max = pClass->stus[i].chinese;
		}
		if(pClass->count.math_max<pClass->stus[i].math){
			pClass->count.math_max = pClass->stus[i].math;
		}
		if(pClass->count.english_max<pClass->stus[i].english){
			pClass->count.english_max = pClass->stus[i].english;
		}
	}
}
void calStusMin(Class * pClass){
	int i=0;
	pClass->count.chinese_min= 9999;
	pClass->count.math_min= 9999;
	pClass->count.english_min= 9999;
	for(;i<pClass->count.allStu;i++){
		if(pClass->count.chinese_min>pClass->stus[i].chinese){
			pClass->count.chinese_min = pClass->stus[i].chinese;
		}
		if(pClass->count.math_min>pClass->stus[i].math){
			pClass->count.math_min = pClass->stus[i].math;
		}
		if(pClass->count.english_min>pClass->stus[i].english){
			pClass->count.english_min = pClass->stus[i].english;
		}
	}
}
void swap(pStu a,pStu b){
	Stu x;x.avg = a->avg;
	x.chinese = a->chinese;
	x.english = a->english;
	x.math = a->math;
	strcpy(x.name,a->name);
	strcpy(x.sno,a->sno);
	x.sum = a->sum;
	a->avg = b->avg;
	a->chinese=b->chinese;
	a->english=b->english;
	a->math=b->math;
	strcpy(a->name,b->name);
	strcpy(a->sno,b->sno);
	a->sum=b->sum;
	b->avg = x.avg;
	b->chinese=x.chinese;
	b->english=x.english;
	b->math=x.math;
	strcpy(b->name,x.name);
	strcpy(b->sno,x.sno);
	b->sum=x.sum;
}
int partition(pStu arr, int start, int last,char *method){
	Stu x = arr[last];
	int i=0,j=0;
	i=start-1;
	for(j=start;j<= last-1; j++){
		if(strcmp(method,"chinese")==0){
			if(arr[j].chinese>= x.chinese){
				++i;
				swap(&arr[i],&arr[j]);
			}
		}
		else if(strcmp(method,"math")==0){
			if(arr[j].math>= x.math){
				++i;
				swap(&arr[i],&arr[j]);
			}
		}
		else if(strcmp(method,"english")==0){
			if(arr[j].english>= x.english){
				++i;
				swap(&arr[i],&arr[j]);
			}
		}
		else if(strcmp(method,"sum")==0){
			if(arr[j].sum>= x.sum){
				++i;
				swap(&arr[i],&arr[j]);
			}
		}
		else if(strcmp(method,"avg")==0){
			if(arr[j].avg>= x.avg){
				++i;
				swap(&arr[i],&arr[j]);
			}
		}
		else if(strcmp(method,"name")==0){
			if(strcmp(arr[j].sno,x.name)==0||strcmp(arr[j].name,x.name)==1){
				++i;
				swap(&arr[i],&arr[j]);
			}
		}
		else{//strcmp(method,"sno")==0
			if(strcmp(arr[j].sno,x.sno)==0||strcmp(arr[j].sno,x.sno)==1){
				++i;
				swap(&arr[i],&arr[j]);
			}
		}
		
	}
	swap(&arr[i+1],&arr[last]);
	return i+1;
}
void quicklySort(pStu arr , int start , int last,char *method){
	int mid;
	if(start<last){
		mid = partition(arr, start, last,method);
		quicklySort(arr, start , mid-1,method);
		quicklySort(arr, mid+1, last,method);
	}
}
void sort(Class * pClass){
	char md[20];
	printf("���������������(please input chinese,math,english,sum,avg,name or sno)��\n");
	scanf("%s",md);
	quicklySort(pClass->stus,0,pClass->count.allStu-1,md);
	printHead();
	printStus(pClass);
}
pStu find(Class * pClass,char *sno){
	int i=0;
	for(;i<pClass->count.allStu;i++){
		if(strcmp(sno,pClass->stus[i].sno)==0){
			return &pClass->stus[i];
		}
	}
}
void printHead(){
	printf("ѧ��\t����\t����\t��ѧ\tӢ��\tƽ����\t�ܷ�\n");
}
void printStu(pStu p_stu){
	if(p_stu==NULL){
		return ;
	}
	if(p_stu->name==NULL||p_stu->sno==NULL){
		return ;
	}
	printf("%s\t%s\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\n",p_stu->sno,p_stu->name,p_stu->chinese,p_stu->math,p_stu->english,p_stu->avg,p_stu->sum);
}
void printStus(Class * pClass){
	int i=0;
	for(;i<pClass->count.allStu;i++){
		printStu(&(pClass->stus[i]));
	}
}
void printCount(Count count){
	printf("ͳ����Ϣ��\n");
	printf("�༶������:%d\n�����ܷ�:%.3f\n��ѧ�ܷ�:%.3f\nӢ���ܷ�:%.3f\n����ƽ����:%.3f\n��ѧƽ����:%f\nӢ��ƽ����:%.3f\n������߷�:%.3f\n��ѧ��߷�:%f\nӢ����߷�:%.3f\n������ͷ�:%.3f\n��ѧ��ͷ�:%.3f\nӢ����ͷ�:%.3f\n",count.allStu,count.chinese_sum,count.math_sum,count.english_sum,count.chinese_avg,count.math_avg,count.english_avg,count.chinese_max,count.math_max,count.english_max,count.chinese_min,count.math_min,count.english_min);
}