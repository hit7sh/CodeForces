for (int b = N - 1; b >= 2; b--) {
        int value = suffix_max[b];
        int start = int(lower_bound(prefix_max.begin(), prefix_max.begin() + b, value) - prefix_max.begin());
        int end = int(upper_bound(prefix_max.begin(), prefix_max.begin() + b, value) - prefix_max.begin());
 
        if (start >= end)
            continue;
 
        int low = start, high = end;
 
        while (low < high) {
            int mid = (low + high) / 2;
 
            if (mid == b || rmq.query_value(mid, b) < value)
                low = mid + 1;
            else
                high = mid;
        }
 
        if (low < b && rmq.query_value(low, b) == value) {
            cout << "YES" << '\n';
            cout << low << ' ' << b - low << ' ' << N - b << '\n';
            return;
        }
    }
 
    cout << "NO" << '\n';
