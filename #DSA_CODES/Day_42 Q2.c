#include <stdlib.h>

typedef struct {
    int maxHeap[50000];
    int minHeap[50000];
    int maxSize;
    int minSize;
} MedianFinder;

void maxHeapifyUp(int *heap, int i){
    while(i>0){
        int p=(i-1)/2;
        if(heap[p]>=heap[i]) break;
        int t=heap[p]; heap[p]=heap[i]; heap[i]=t;
        i=p;
    }
}

void minHeapifyUp(int *heap, int i){
    while(i>0){
        int p=(i-1)/2;
        if(heap[p]<=heap[i]) break;
        int t=heap[p]; heap[p]=heap[i]; heap[i]=t;
        i=p;
    }
}

void maxHeapifyDown(int *heap,int size,int i){
    while(1){
        int l=2*i+1,r=2*i+2,largest=i;
        if(l<size && heap[l]>heap[largest]) largest=l;
        if(r<size && heap[r]>heap[largest]) largest=r;
        if(largest==i) break;
        int t=heap[i]; heap[i]=heap[largest]; heap[largest]=t;
        i=largest;
    }
}

void minHeapifyDown(int *heap,int size,int i){
    while(1){
        int l=2*i+1,r=2*i+2,small=i;
        if(l<size && heap[l]<heap[small]) small=l;
        if(r<size && heap[r]<heap[small]) small=r;
        if(small==i) break;
        int t=heap[i]; heap[i]=heap[small]; heap[small]=t;
        i=small;
    }
}

MedianFinder* medianFinderCreate(){
    MedianFinder* obj=malloc(sizeof(MedianFinder));
    obj->maxSize=0;
    obj->minSize=0;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj,int num){

    obj->maxHeap[obj->maxSize]=num;
    maxHeapifyUp(obj->maxHeap,obj->maxSize++);
    
    obj->minHeap[obj->minSize]=obj->maxHeap[0];
    obj->maxHeap[0]=obj->maxHeap[--obj->maxSize];
    maxHeapifyDown(obj->maxHeap,obj->maxSize,0);
    minHeapifyUp(obj->minHeap,obj->minSize++);

    if(obj->maxSize<obj->minSize){
        obj->maxHeap[obj->maxSize]=obj->minHeap[0];
        obj->minHeap[0]=obj->minHeap[--obj->minSize];
        minHeapifyDown(obj->minHeap,obj->minSize,0);
        maxHeapifyUp(obj->maxHeap,obj->maxSize++);
    }
}

double medianFinderFindMedian(MedianFinder* obj){
    if(obj->maxSize>obj->minSize)
        return obj->maxHeap[0];
    return (obj->maxHeap[0]+obj->minHeap[0])/2.0;
}

void medianFinderFree(MedianFinder* obj){
    free(obj);
}
