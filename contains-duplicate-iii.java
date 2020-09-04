public class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        if (t < 0) {
            return false;
        }
        
        long size = t + 1;
        Map<Long, Long> map = new HashMap<>();
        
        for (int i = 0; i < nums.length; i++) {
            long bucket = getBucket(nums[i], size);
            if (map.containsKey(bucket)) {
                return true;
            }
            if (map.containsKey(bucket - 1) && (long) nums[i] - map.get(bucket - 1) <= t) {
                return true;
            }
            if (map.containsKey(bucket + 1) && map.get(bucket + 1) - (long) nums[i] <= t) {
                return true;
            }
            map.put(bucket, (long) nums[i]);
            if (i >= k) {
                map.remove(getBucket(nums[i - k], size));
            }
        }
        
        return false;
    }
    
    private long getBucket(int number, long size) {
        return number < 0 ? number / size - 1 : number / size;
    }
}
