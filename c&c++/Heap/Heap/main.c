#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // 힙의 최대 크기

typedef struct {
    int data[MAX_SIZE]; // 힙을 저장할 배열
    int size;           // 현재 힙의 크기
} MaxHeap;

// 힙 초기화
void initHeap(MaxHeap *heap) {
    heap->size = 0;
}

// 부모, 왼쪽 자식, 오른쪽 자식의 인덱스 계산
int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return 2 * i + 1;
}

int rightChild(int i) {
    return 2 * i + 2;
}

// 힙 속성 유지 (Heapify - Downheap)
void heapifyDown(MaxHeap *heap, int i) {
    int largest = i;
    int left = leftChild(i);
    int right = rightChild(i);
    
    // 왼쪽 자식이 더 크다면 largest 갱신
    if (left < heap->size && heap->data[left] > heap->data[largest]) {
        largest = left;
    }
    
    // 오른쪽 자식이 더 크다면 largest 갱신
    if (right < heap->size && heap->data[right] > heap->data[largest]) {
        largest = right;
    }
    
    // largest가 변경되었다면 스왑 후 재귀 호출
    if (largest != i) {
        int temp = heap->data[i];
        heap->data[largest] = heap->data[largest];
        heap->data[largest] = temp;
        
        heapifyDown(heap, largest);
    }
}

void heapifyUpFromBottom(MaxHeap *heap) {
    int start = (heap->size - 2) / 2;       // 마지막 리프 노드의 부모부터 시작
    
    // 아래에서 위로 모든 노드에 대해 heapify
    while (start >= 0) {
        int i = start;
        
        // while 루프를 사용해 down-heap 수행
        while(i < heap->size) {
            int largest = i;
            int left = leftChild(i);
            int right = rightChild(i);
            
            // 왼쪽 자식이 더 크다면 largest 갱신
            if (left < heap->size && heap->data[left] > heap->data[largest]) {
                largest = left;
            }

            // 오른쪽 자식이 더 크다면 largest 갱신
            if (right < heap->size && heap->data[right] > heap->data[largest]) {
                largest = right;
            }
            
            // 힙 속성이 만족되면 중단
            if (largest == i) {
                break;
            }
            
            // largest와 교환
            int temp = heap->data[i];
            heap->data[i] = heap->data[largest];
            heap->data[largest] = temp;
            
            // 이동
            i = largest;
        }
        
        // 다음 부모 노드로 이동
        start--;
    }
}

// 힙의 새 요소 삽입
void insert(MaxHeap *heap, int value) {
    if (heap->size >= MAX_SIZE) {
        printf("Heap overflow!\n");
        return;
    }
    
    // 새로운 값을 힙의 끝에 추가
    heap->data[heap->size] = value;
    int i = heap->size;
    heap->size++;
    
    // Upheap: 부모와 비교하여 힙 속성 유지
    while (i > 0 && heap->data[parent(i)] < heap->data[i]) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[parent(i)];
        heap->data[parent(i)] = temp;
        
        i = parent(i);
    }
}

// 힙의 최댓값 제거 및 반환
int extractMax(MaxHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap underflow!\n");
        return -1; // 에러 값
    }
    
    // 루트 노드 (최댓값)를 저장
    int maxValue = heap->data[0];
    
    // 마지막 노드를 루트로 이동
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    
    // Downheap으로 힙 속성 유지
    heapifyDown(heap, 0);
    
    return maxValue;
}

// 힙 출력
void printHeap(MaxHeap *heap) {
    for (int i=0; i<heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    MaxHeap heap;
    initHeap(&heap);

    // 힙에 요소 삽입
    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 5);
    insert(&heap, 7);
    insert(&heap, 25);

    printf("Heap after insertions: ");
    printHeap(&heap);

    // 최댓값 제거
    printf("Extracted max: %d\n", extractMax(&heap));
    printf("Heap after extraction: ");
    printHeap(&heap);
    
    return 0;
}
