#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

#define N 1000
typedef struct {
    int x;
    int y;
    int z;
} v3;

typedef struct {
    long long int d;
    int i;
    int j;
} ijd;

vector<v3> ReadPointsInput() {
    vector<v3> v(N);
    for (int i = 0; i < N; i++) {
        scanf("%i,%i,%i\n", &v[i].x, &v[i].y, &v[i].z);
    }
    return v;
}

long v3distance(v3 v, v3 u) {
    long dx = (long)v.x - (long)u.x;
    long dy = (long)v.y - (long)u.y;
    long dz = (long)v.z - (long)u.z;
    return dx*dx + dy*dy + dz*dz;
}

bool comp(ijd a, ijd b) {
    return a.d < b.d;
}

vector<ijd> PointsDistance(vector<v3> v) {
    vector<ijd> dv;
    dv.reserve(((N+1)/2)*N);
    // Loop ensures no duplicates and no self refrences 
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            long long int d = v3distance(v[i], v[j]);
            dv.push_back((ijd){.d = v3distance(v[i], v[j]), .i = i, .j = j});
        }
    }
    sort(dv.begin(), dv.end(), comp);
    return dv;
}

bool AlreadyConnected(vector<vector<int>> &adj, int i, int j) { 
    vector<int> stack = {i};
    vector<bool> visited(N, false);

    visited[i] = true;
    while (!stack.empty()) {
        auto a = stack.back();
        stack.pop_back();
        for (auto b : adj[a]) {
            if (b == j) return true;
            if (!visited[b]) {
                visited[b] = true;
                stack.push_back(b);
            }
        }
    }
    return false;
}

int main() {

    vector<v3> points = ReadPointsInput();
    vector<ijd> distances = PointsDistance(points);

    vector<vector<int>> adj(N);
    vector<bool> v(N);

    int conn = 0;
    ijd prevd; 
    for (auto d : distances) {
        if (!(conn < (N - 1))) break;
        if (d.d == 0) continue; // same points
        if (AlreadyConnected(adj, d.i, d.j)) continue;
        conn++;
        adj[d.i].push_back(d.j);
        adj[d.j].push_back(d.i);
        v[d.i] = true;
        v[d.j] = true;
        prevd = d;
    }

    cout << (long)(points[prevd.i].x) * (long)(points[prevd.j].x) << endl;
    return 0;
}