#define _CRT_SECURE_NO_WARNINGS
#include"sort.h"
#include"Stack.h"
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void InsertSort(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0) {
			if (tmp < a[end]) {
				a[end + 1] = a[end];
				end--;
			}
			else {
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n) {
	int gap = n;
	while (gap > 1) {
		gap = gap / 3 +1;
		for (int i = 0; i < n - gap; i++) {
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0) {
				if (tmp < a[end]) {
					a[end + gap] = a[end];
					end-=gap;
				}
				else {
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void SelectSort(int* a, int n) {
	int begin = 0, end = n - 1;
	while (begin < end) {
		int maxi = end, mini = begin;
		for (int i = begin; i <= end; i++) {
			if (a[i] > a[maxi]) {
				maxi = i;
			}
			if (a[i] < a[mini]) {
				mini = i;
			}
		}
		if ((maxi == begin) ) {
			maxi = mini;
		}
		Swap(&a[begin], &a[mini]);
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}

}

void AdjustDwon(int* a, int parent, int n) {
	int child = parent * 2 + 1;
	while (child < n) {
		//小> 大<
		if ((a[child] < a[child + 1]) && child + 1 < n) {//还有个越界别忘了
			child++;
		}

		if (a[parent] < a[child]) {
			Swap(&a[parent], &a[child]);
		}
		else {
			break;//节省时间
		}
		parent = child;
		child = parent * 2 + 1;
	}
}
void HeapSort(int* a, int n) {
	//先建堆
	for (int i = (n-1-1) / 2; i >= 0; i--) {
		AdjustDwon(a, i, n);
	}

	//堆排序
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, 0, end);
		end--;
	}
}
//快排
void QuickSort(int* a, int left, int right) {
	if (left >= right) {
		return;
	}
	//int key = PartSort1(a, left, right);
	//int key = PartSort2(a, left, right);
	int key = PartSort3(a, left, right);
	QuickSort(a, left, key - 1);
	QuickSort(a, key + 1, right);
}

int PartSort1(int* a, int left, int right) {
	int key = left;
	++left;
	while (left <= right) {
		//找左侧大的,先动right，因为要在右边有个边界,取等的话
		while (left <= right && (a[right] > a[key])) {
			right--;
		}
		//找右侧小的
		while (left <= right && (a[left] < a[key])) {
			left++;
		}
		if (left <= right) {
			Swap(&a[left++], &a[right--]);
		}
	}
	Swap(&a[key], &a[right]);
	return right;
}

// 快速排序挖坑法
int PartSort2(int* a, int left, int right) {
	int hole = left;
	while (left < right) {
		while (right > left && a[right] > a[hole]) {
			right--;
		}
		Swap(&a[hole], &a[right]);
		hole = right;
		while (right > left && a[left] < a[hole]) {
			left++;
		}
		Swap(&a[hole], &a[left]);
		hole = left;
	}
	return hole;
}
// 快速排序前后指针法
int PartSort3(int* a, int left, int right) {
	int prev = left, cur = prev + 1;
	int key = left;
	while (cur <= right) {
		if (a[cur] < a[key] && ++prev != cur) {//这里着重注意一下++Prev，是先++后交换
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	Swap(&a[key], &a[prev]);
	return prev;
}
//非递归版本(也是通过某种方式存储)
//void QuickSortNonR(int* a, int left, int right) {
//	ST st;
//	STInit(&st);
//	StackPush(&st, right);
//	StackPush(&st, left);
//	while (!StackEmpty(&st)) {
//		//取栈顶*2
//		int begin = StackTop(&st);
//		StackPop(&st); 
//		int end = StackTop(&st);
//		StackPop(&st);
//		//交换
//		int keyi = begin;
//		int prev = begin, cur = prev + 1;
//		while (cur <= end) {
//			if (a[cur] < a[keyi] && ++prev != cur) {
//				Swap(&a[prev], &a[cur]);
//			}
//
//			++cur;
//		}
//		Swap(&a[keyi], &a[prev]);
//
//		keyi = prev;//这里用keyi防止混淆，但其实用Prev一样
//		// begin  keyi   end 
//		if (prev - 1 > begin) {
//			StackPush(&st, prev - 1);
//			StackPush(&st, begin);
//		}
//		if (prev + 1 < end) {
//			StackPush(&st, end);
//			StackPush(&st, prev + 1);
//		}
//	}
//	STDestory(&st);
//}

//快排三路划分
void PartSort4(int* a, int left, int right) {
	if (left >= right) {
		return;
	}

	int key = a[left];
	int begin = left, end = right;
	int cur = left + 1;
	//Swap(&a[cur], &a[left]);
	while (cur <= right) {
		if (key < a[cur]) {
			Swap(&a[right], &a[cur]);
			right--;
		}
		else if (key > a[cur]) {
			Swap(&a[left], &a[cur]);
			left++, cur++;
		}
		else {
			cur++;
		}
			
	}
	
	//[begin,left-1][left,right][right+1,end]
	PartSort4(a, begin, left - 1);
	PartSort4(a, right+1, end);

}