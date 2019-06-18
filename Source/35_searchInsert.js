/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function (nums, target) {
    nums.push(target);
    nums.sort(function(a ,b) {
        return a - b;
    });
    
    return nums.indexOf(target);
};