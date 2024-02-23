<h2><a href="https://leetcode.com/problems/the-wording-game/">2868. The Wording Game</a></h2><h3>Hard</h3><hr><div><p>Alice and Bob each have a <strong>lexicographically sorted</strong> array of strings named <code>a</code> and <code>b</code> respectively.</p>

<p>They are playing a wording game with the following rules:</p>

<ul>
	<li>On each turn, the current player should play a word from their list such that the new word is <strong>closely greater</strong> than the last played word; then it's the other player's turn.</li>
	<li>If a player can't play a word on their turn, they lose.</li>
</ul>

<p>Alice starts the game by playing her <strong>lexicographically </strong><strong>smallest </strong>word.</p>

<p>Given <code>a</code> and <code>b</code>, return <code>true</code> <em>if Alice can win knowing that both players play their best, and</em> <code>false</code> <em>otherwise.</em></p>

<p>A word <code>w</code> is <strong>closely greater</strong> than a word <code>z</code> if the following conditions are met:</p>

<ul>
	<li><code>w</code> is <strong>lexicographically greater</strong> than <code>z</code>.</li>
	<li>If <code>w<sub>1</sub></code> is the first letter of <code>w</code> and <code>z<sub>1</sub></code> is the first letter of <code>z</code>, <code>w<sub>1</sub></code> should either be <strong>equal</strong> to <code>z<sub>1</sub></code> or be the <strong>letter after</strong> <code>z<sub>1</sub></code> in the alphabet.</li>
	<li>For example, the word <code>"care"</code> is closely greater than <code>"book"</code> and <code>"car"</code>, but is not closely greater than <code>"ant"</code> or <code>"cook"</code>.</li>
</ul>

<p>A string <code>s</code> is <b>lexicographically </b><strong>greater</strong> than a string <code>t</code> if in the first position where <code>s</code> and <code>t</code> differ, string <code>s</code> has a letter that appears later in the alphabet than the corresponding letter in <code>t</code>. If the first <code>min(s.length, t.length)</code> characters do not differ, then the longer string is the lexicographically greater one.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> a = ["avokado","dabar"], b = ["brazil"]
<strong>Output:</strong> false
<strong>Explanation:</strong> Alice must start the game by playing the word "avokado" since it's her smallest word, then Bob plays his only word, "brazil", which he can play because its first letter, 'b', is the letter after Alice's word's first letter, 'a'.
Alice can't play a word since the first letter of the only word left is not equal to 'b' or the letter after 'b', 'c'.
So, Alice loses, and the game ends.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> a = ["ananas","atlas","banana"], b = ["albatros","cikla","nogomet"]
<strong>Output:</strong> true
<strong>Explanation:</strong> Alice must start the game by playing the word "ananas".
Bob can't play a word since the only word he has that starts with the letter 'a' or 'b' is "albatros", which is smaller than Alice's word.
So Alice wins, and the game ends.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> a = ["hrvatska","zastava"], b = ["bijeli","galeb"]
<strong>Output:</strong> true
<strong>Explanation:</strong> Alice must start the game by playing the word "hrvatska".
Bob can't play a word since the first letter of both of his words are smaller than the first letter of Alice's word, 'h'.
So Alice wins, and the game ends.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= a.length, b.length &lt;= 10<sup>5</sup></code></li>
	<li><code>a[i]</code> and <code>b[i]</code> consist only of lowercase English letters.</li>
	<li><code>a</code> and <code>b</code> are <strong>lexicographically sorted</strong>.</li>
	<li>All the words in <code>a</code> and <code>b</code> combined are <strong>distinct</strong>.</li>
	<li>The sum of the lengths of all the words in <code>a</code> and <code>b</code> combined does not exceed <code>10<sup>6</sup></code>.</li>
</ul>
</div>