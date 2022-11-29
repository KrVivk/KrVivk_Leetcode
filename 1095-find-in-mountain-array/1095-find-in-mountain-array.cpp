/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length(), low, high , mid , peak = 0;
        low  = 0;
        high = n - 1;
        while (low < high) {
            mid = (low + high) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                low = peak = mid + 1;
            else
                high = mid;
        }
        low = 0;
        high = peak;
        while (low <= high) {
            mid = (low + high) / 2;
            if (mountainArr.get(mid) < target)
                low = mid + 1;
            else if (mountainArr.get(mid) > target)
                high = mid - 1;
            else
                return mid;
        }
        low = peak;
        high = n - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (mountainArr.get(mid) > target)
                low = mid + 1;
            else if (mountainArr.get(mid) < target)
                high = mid - 1;
            else
                return mid;
        }
        return -1;
    }
};
        

