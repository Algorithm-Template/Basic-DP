vector<ll> lis(vector<ll> const& a) {
    ll n = a.size();
    const ll INF = 1000000100;
    vector<ll> d(n+1, INF);
    d[0] = -INF;

    vector<ll>dd[n+1];
    dd[0].push_back(-INF);
    for(ll i=1; i<=n; i++) dd[i].push_back(INF);

    for (ll i = 0; i < n; i++) {
        ll l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[l-1] < a[i] && a[i] < d[l]) {
            d[l] = a[i];
            dd[l].push_back(a[i]);
        }
    }

    ll ans = 0; // lis lenth
    for (ll l = 0; l <= n; l++) {
        if (d[l] < INF)
            ans = l;
    }
    vector<ll>v;
    ll mx=INF;
    for(ll i=ans; i>0; i--) {
        ll L=0,R=dd[i].size()-1;
        ll l=0;
        while(L<=R){
            ll mid=(L+R)/2;
            if(mx>dd[i][mid]){
                l=mid;
                R=mid-1;
            }
            else{
                L=mid+1;
            }
        }
        v.push_back(dd[i][l]); mx=dd[i][l];
    }
    reverse(v.begin(),v.end());
    return v;
}
