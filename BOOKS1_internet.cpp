#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
 
typedef long long int ll;
 
const int MAX = 505;
 
ll M, K;                // Luu s? lu?ng cu?n s�ch, v� s? ph?n c?n chia
ll Left,Right, mid;        
ll Page[MAX];           // Luu s? lu?ng trang s�ch c?a m?i cu?n
ll Index[MAX];          // M?ng luu ch? s? c?a ph?n t? d?u ti�n c?a m?i ph?n
ll ValidIndex[MAX];     // K?t qu? cu?i c�ng
 
// C?p nh?t l?i t?ng ph?n sao cho t?ng m?i ph?n kh�ng l?n hon mid
void Update(ll id)
{
    ll sum = 0, t = Index[id];
 
    for(ll i = Index[id + 1] - 1; i >= t; i--)
    {
        sum += Page[i];
        
        if(sum == mid)
        {
            Index[id] = i;
            break;
        }else if(sum > mid)
        {
            Index[id] = i + 1;
            break;
        }
    }
}
 
// Ki?m tra xem v?i v?i s? lu?ng l?n nh?t c?a c�c ph?n l� mid
// c� h?p l? hay kh�ng
bool IsValid()
{
    for(int i = 0; i < K; i++)
        Index[i] = i;
    Index[K] = M;
 
    // C?p nh?t l?i t?ng ph?n
    for(int i = K - 1; i >= 0; i--)
        Update(i);
 
    // N?u sau
    if (Index[0] > 0) return false;
 
    return true;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
 
    // comment d�ng n�y tru?c khi submit
    freopen("books1.txt","r",stdin);
 
    int T;
    cin >> T;
 
    for(int tc = 0; tc < T; tc++)
    {
        ll max_page = 0;        // T�m ra cu?n s�ch c� nhi?u trang nh?t
        ll sum_page = 0;        // T�m t?ng s? trang
        
        cin >> M >> K;
 
        for(int i = 0; i < M; i++)
        {
            cin >> Page[i];
 
            if(Page[i] > max_page) max_page = Page[i];
            sum_page += Page[i];
        }
            
        // Khi chia ra th�nh c�c ph?n, th� t?ng l?n nh?t c?a c�c ph?n
        // s? n?m trong kho?ng t? Left = max_page (s? trang nhi?u nh?t)
        // v� Right = sum_page (s? trang nhi?u nh?t)
        Left  = max_page;
        Right = sum_page;
 
        // Tri?n khai thu?t to�n chia d? tr?
        while (Left < Right)
        {
            mid = (Left + Right) / 2;
            
            if (IsValid())
            {
                Right = mid;
                
                // Ta d�ng m?ng d? luu l?i ch? s? c?a c�c ph?n t?
                // d? ph�n chia c�c ph?n.
                for(int i = 0; i < K; i++)
                    ValidIndex[i] = Index[i];
            }
            else
            {
                Left = mid + 1;
            }
        }
 
        // In ra k?t qu?
        for(int i = 0; i < K - 1; i++)
        {
            for(int j = ValidIndex[i]; j < ValidIndex[i+1]; j++)
                cout << Page[j] << " ";
            cout << "/ ";
        }
        
        for(int i = ValidIndex[K-1]; i < M; i++)
        {
            cout << Page[i];
            if(i == M-1) break;
            cout << " ";
        }
 
        cout << endl;
    }
 
    return 0;
}
