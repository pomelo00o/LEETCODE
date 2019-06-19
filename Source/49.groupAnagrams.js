/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    var result = [];
    while (strs.length > 0) {
        var target = new Word(strs[0]);
        strs.shift();
        for (var i = 0; i < strs.length; ++i) {
            var curr = new Word(strs[i]);
            if (target._equals(curr)) {
                target.arr.push(strs[i]);
            }
            var index = strs.indexOf(curr);
            strs.splice(index, 1);
        }
        result.push(target.arr);
    }
    return result;
};

function Word(str) {
    this.len = str.length;
    this.letters = str.split("").sort();
    this.arr = [str];
}

Word.prototype._equals = function(w) {
    if (this.len === w.len) {
        for (var i = 0; i < this.len; ++i) {
            if (this.letters[i] !== w.letters[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
};

// test
console.log(groupAnagrams(["eat","tea","tan","ate","nat","bat"]));