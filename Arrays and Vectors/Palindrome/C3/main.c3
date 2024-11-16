import std::io;
import libc;

fn bool checkPalindrome(String word) {
  usz half = word.len/2;

  for (int i = 0; i < half; i++) {
    if (word[i] != word[word.len-1-i]) {
      return false;
    }
  }

  return true;
}

fn void main(String[] args)
{
  if (args.len == 1) {
    io::printf("Usage: %s <word1> [<word2> ...]\n", args[0]);

    libc::exit(libc::EXIT_SUCCESS);
  }

  args = args [1..];

  foreach (arg : args) {
    io::printn(checkPalindrome(arg));
  }
}
