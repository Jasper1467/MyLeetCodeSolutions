impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if (x < i32::MIN) || (x > i32::MAX) {
            return false;
        }

        let s: String = x.to_string();
        return s == s.chars().rev().collect::<String>();
    }
}
