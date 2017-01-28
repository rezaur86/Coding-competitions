package ctci;

public class QuickSort {
	public void quickSort(int[] nums, int left, int right) {
		int idx = partition(nums, left, right);
		if (left < idx -1) {
			quickSort(nums, left, idx-1);
		} 
		if (idx < right) {
			quickSort(nums, idx, right);
		}
	}
    public int partition(int[] nums, int left, int right) {
        int pivot = nums[(left + right) / 2];
        while(left <= right) {
            while(nums[left] < pivot) {
                left++;
            }
            while(nums[right] > pivot) {
                right--;
            }
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
        return left;
    }
}
