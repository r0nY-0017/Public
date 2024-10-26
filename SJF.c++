/*                                    ✩｡:*•.─────❁  بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ  ❁─────.•*:｡✩                                     */
#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "---------Shortest Job First---------\n\n";
    int n, a,b,at, bt, ct, tat, wt;
    vector<vector<int>> SJF;
    vector<int> v;
    cout << "Enter Number of Process: ";
    cin >> n;
    for(int i=0; i<n; i++){
        cout << "Enter AT & BT for Process-" << i+1 << " : ";
        cin >> a >> b;
        v.push_back(a);
        v.push_back(b);
        v.push_back(i+1);
        SJF.push_back(v);
        v.clear();
    }

    sort(SJF.begin(), SJF.end()); //AT Basis, AT Same hoile BT

    for(int i=0; i<n; i++){
        swap(SJF[i].front(), SJF[i].back());
        swap(SJF[i].back(), SJF[i][1]);
    }

    int cur = 0, mnbt, idx;
    int sum_at = 0, sum_bt = 0, sum_ct = 0;
    int sum_tat = 0, sum_wt = 0;
    cout << "\n\nGantt Chart:\n";
    cout << cur << "___";
    for(int i=0; i<n; i++){
        mnbt = 9999, idx = i;
        for(int j=i; j<n; j++){
            if(SJF[j][1]<=cur){
                if(mnbt > SJF[j][2]){
                    mnbt = SJF[j][2];
                    idx = j;
                }
            }
        }

        swap(SJF[i], SJF[idx]);

        at = SJF[i][1], sum_at += at;
        bt = SJF[i][2], sum_bt += bt;

        if(at>cur){
            cout << "(Idle)___";
            cur = at;
            cout << cur << "___";
        }
        cout << "(P" << SJF[i].front() << ")___";
        ct = cur + bt, sum_ct  += ct;
        tat = ct - at, sum_tat += tat;
        wt = tat - bt, sum_wt  += wt;
        SJF[i].push_back(ct);
        SJF[i].push_back(tat);
        SJF[i].push_back(wt);
        cur = ct;
        if(i+1==n) cout << cur;
        else cout << cur << "___";
    }
    
    sort(SJF.begin(), SJF.end());

    cout << "\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=0; i < SJF.size(); i++){
        for(int j=0; j < SJF[i].size(); j++){
            if(j==0) cout << "P";
            cout << SJF[i][j] << "\t";
        }    
        cout << endl;
    }
    cout << "------------------------------------------\n";
    cout << "Total\t" << sum_at << "\t" << sum_bt << "\t";
    cout << sum_ct << "\t" << sum_tat << "\t" << sum_wt << "\n";
    cout << "\nAverage TAT : " << (float(sum_tat)/n) << endl;
    cout << "Average WT : " << (float(sum_wt)/n) << endl;
return 0;
}
