#include <iostream>
#include <climits> // INT_MAX를 위해 필요

#define I INT_MAX

// std namespace는 명시적으로 사용
int edges[3][9] = {
    {1,1,2,2,3,4,4,5,5},
    {2,6,3,7,4,5,7,6,7},
    {25,5,12,10,8,16,14,20,18}
};

int set[10] = {-1}; // 배열 크기를 확장
int included[9] = {0};
int t[2][6] = {0};  // 배열 초기화

void MyUnion(int u, int v) {
    if (set[u] < set[v]) {
        set[u] += set[v];
        set[v] = u;
    } else {
        set[v] += set[u];
        set[u] = v;
    }
}

int find(int u) {
    int x = u, v = 0;
    
    while (set[x] > 0) {
        x = set[x];
    }
    
    while (u != x) {
        v = set[u];
        set[u] = x;
        u = v;
    }
    
    return x;
}

int main() {
    int i, j, k, u, v, min, n = 7, e = 9;
    
    i = 0;
    while (i < n - 1) {
        min = INT_MAX; // 명확히 초기화
        
        for (j = 0; j < e; j++) {
            if (included[j] == 0 && edges[2][j] < min) {
                min = edges[2][j];
                u = edges[0][j];
                v = edges[1][j];
                k = j;
            }
        }
        
        if (find(u) != find(v)) {
            t[0][i] = u;
            t[1][i] = v;
            MyUnion(find(u), find(v));
            i++;
        }
        
        included[k] = 1;
    }
    
    for (i = 0; i < n - 1; i++) {
        std::cout << "(" << t[0][i] << "," << t[1][i] << ")" << std::endl;
    }
    
    return 0;
}
