package main

import (
	"fmt"
	"strings"
)

func CheckPalindrome(str string) bool {
	trimmed_str := strings.Trim(str, " ")
	len_str := len(str)

	for i := 0; i < len_str/2; i++ {
		if trimmed_str[i] != trimmed_str[len_str-i-1] {
			return false
		}
	}

	return true
}

func main() {
	var input string

	for {
		_, err := fmt.Scanln(&input)
		if err != nil {
			break
		}

		if input == "exit" {
			break
		}

		fmt.Println(CheckPalindrome(input))
	}
}
