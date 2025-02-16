#include <bits/stdc++.h>
using namespace std;
#define MAXN 5005
#define ALPHABETSIZE 26
#define ll long long
ll M;
vector<vector<ll>> multiply(vector<vector<ll>> &A, vector<vector<ll>> &B) {
    int n = A.size(); // Assuming square matrices
    vector<vector<ll>> result(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
                result[i][j] %= M;
            }
        }
    }

    return result;
}
vector<vector<ll>> power(vector<vector<ll>> &x, ll y)
{
    ll n = x.size();
    vector<vector<ll>> iden(x.size(), vector<ll>(x.size(), 0));
    for (int i = 0; i < n; i++) {
        iden[i][i] = 1;
    }
    if (y == 0)
        return iden;
    vector<vector<ll>> result;
    result = power(x, y / 2);
    result = multiply(result, result);
    return (y % 2 == 0) ? result : multiply(result, x);
}
vector<ll> vectorMatrixMultiply(vector<ll> &vec, vector<vector<ll>> &matrix) {
    int m = vec.size(); // The size of the vector (1 * m)
    int n = matrix.size(); // The size of the matrix (m * m)

    // Initialize the result vector of size 1 * m
    vector<ll> result(m, 0);

    // Perform the multiplication
    for (int j = 0; j < m; j++) { // Loop over columns of the matrix
        for (int k = 0; k < m; k++) { // Multiply each element in the vector with the corresponding row
            result[j] += (vec[k] * matrix[k][j]) % M;
            result[j] %= M;
        }
    }

    return result;
}
int main()
{
    M = 1e9 + 7;
    ll n, k; cin >> n >> k;
    vector<ll> track(16);
    track[0] = 1;
    for(int i = 0; i < n; i++){
        ll a, b, y; cin >> a >> b >> y;
        if(i == n - 1) b = k;
        vector<vector<ll>> matrix(y + 1, vector<ll> (y + 1));
        for(int j1 = 0; j1 <= y; j1++){
            for(int j2 = 0; j2 <= y; j2++){
                if(abs(j1 - j2) <= 1){
                    matrix[j1][j2] = 1;
                }
                else{
                    matrix[j1][j2] = 0;
                }
            }
        }
        vector<vector<ll>> get = power(matrix, b - a);
        // for(int i = 0; i <= y; i++){
        //     for(int j = 0; j <= y; j++){
        //         cout << get[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        vector<ll> temp(y + 1);
        for(int i = 0; i <= y; i++) temp[i] = track[i];
        // for(auto j: temp) cout << j << " ";
        // cout << "\n";
        vector<ll> temp2 = vectorMatrixMultiply(temp, get);
        for(int i = 0; i <= y; i++){
            track[i] = temp2[i];
        }
        for(int i = y + 1; i <= 15; i++){
            track[i] = 0;
        }
        // for(int i = 0; i <= 15; i++){
        //     cout << track[i] << " ";
        // }
        // cout << "\n";
    }
    cout << track[0] << "\n";

}