# Space-Shooter-Game
Developed a Space Shooter game using C++ in Visual Studio to strengthen my understanding of core programming concepts. The project includes player controls, enemy AI, health management, and a scoring system, demonstrating my ability to implement complex logic and manage real-time user interactions effectively.
<h1>🎮 Endless Runner Game</h1>
<p>A console-based game where you control a runner, dodge hurdles, collect coins, and survive as long as possible while maintaining health and increasing your score.</p>

<h2>📌 Features</h2>
<p><strong>• Runner Control:</strong> Move up, down, left, or right within the game board.</p>
<p><strong>• Hurdles:</strong> Avoid obstacles to prevent losing health.</p>
<p><strong>• Coins:</strong> Collect coins to increase your score.</p>
<p><strong>• Dynamic Difficulty:</strong> The game speed increases as you progress.</p>
<p><strong>• Game Over Screen:</strong> Displays a message when health reaches zero.</p>

<h2>🎮 How to Play</h2>
<h3>1. Start the Game</h3>
<p>Run the program and follow the on-screen instructions.</p>

<h2>2. Controls</h2>
<p>↑ W: Move Up</p>
<p>↓ S: Move Down</p>
<p>→ D: Move Right</p>
<p>← A: Move Left</p>
<p>Spacebar: Jump</p>

<h2>3. Objective</h2>
<p>• Dodge hurdles (H) appearing randomly.</p>
<p>• Collect coins (o) to increase your score.</p>
<p>• Survive as long as possible without losing health.</p>

<h2>4. Game Information</h2>
<p><strong>• Health:</strong> Displayed as hearts (+).</p>
<p><strong>• Score:</strong> Tracks the number of collected coins.</p>
<p><strong>• Distance:</strong> Measures progress in the game.</p>

<h2>📝 Instructions</h2>
<p>• Avoid hitting obstacles; each collision reduces health.</p>
<p>• Move strategically to collect coins and avoid hurdles.</p>
<p>• The game dynamically updates based on progress.</p>

<h2>🛠 Code Structure</h2>
<h3>🔑 Key Functions</h3>
<p><strong>arrPopulation()</strong> → Initializes the game board.</p>
<p><strong>showBoard()</strong> → Displays health, score, and distance.</p>
<p><strong>showRunner()</strong> → Places the runner on the board.</p>
<p><strong>MoveRunner()</strong> → Handles user input for movement.</p>
<p><strong>Hurdle(), HurdleDown()</strong> → Generates and moves hurdles.</p>
<p><strong>coins(), coinsDown()</strong> → Generates and moves coins.</p>
<p><strong>GameOver()</strong> → Ends the game when health reaches zero.</p>

<h2>🎯 Game Logic</h2>
<p>• The game runs in a loop until health reaches zero.</p>
<p>• Speed increases as distance progresses.</p>

<h2>⚙ Requirements</h2>
<p><strong>• Compiler:</strong> C++ compiler (GCC, MSVC).</p>
<p><strong>• OS:</strong> Works on Windows (uses &lt;conio.h&gt; for input).</p>

<h2>📚 Library Dependencies</h2>
<p><strong>&lt;iostream&gt;</strong> → Input/output operations</p>
<p><strong>&lt;iomanip&gt;</strong> → Formatted output</p>
<p><strong>&lt;cstdlib&gt; &amp; &lt;ctime&gt;</strong> → Random number generation</p>
<p><strong>&lt;conio.h&gt;</strong> → Non-blocking keyboard input</p>

<h2>▶ How to Compile and Run</h2>
<p><strong>1.</strong> Save the code in a file named <code>EndlessRunner.cpp</code>.</p>
<p><strong>2.</strong> Open a terminal and navigate to the directory containing the file.</p>
<p><strong>3.</strong> Compile the code using a C++ compiler:</p>
<pre><code>g++ EndlessRunner.cpp -o EndlessRunner</code></pre>
<p><strong>4.</strong> Run the game using:</p>
<pre><code>./EndlessRunner</code></pre>

<h2>🚀 Enjoy the game and test your reflexes in this exciting Endless Runner adventure! 🎮✨</h2>
