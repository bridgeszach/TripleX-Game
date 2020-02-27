#include <iostream>
#include <ctime>

// Text changes based on difficulty level
void LevelOne(int Difficulty)
{
    // Print welcome messages to terminal
    std::cout << "\n\nYou wake up in a haze, unsure of where you are. The dark room is illuminated by the glow of a computer screen...";
    std::cout << "\n";
    std::cout << "The terminal shows five blank fields and reads: \"Enter the Level " << Difficulty << " code to exit...\"\n";
}

void LevelTwo(int Difficulty)
{
    // Prints new text for levels 2 through 5
    std::cout << "\n\n The terminal now reads: \"Enter the Level " << Difficulty << " code to exit...\"\n ";
}

void LevelThree(int Difficulty)
{
    std::cout << "\n You hear the sound of air wheezing to a stop as the vent closes.\n";
    std::cout << "The terminal reads: \"Enter the Level " << Difficulty << " code.\"\n";
}

void LevelFour(int Difficulty)
{
    std::cout << "\n The room begins to heat up.\n";
    std::cout << "The terminal reads: \"Enter the Level " << Difficulty << " code.\"\n";
}

void LevelFive(int Difficulty)
{
    std::cout << "\n You notice the air becoming thin, making it harder to breathe. Time is running out..\n";
    std::cout << "The terminal reads: \"Enter the Level " << Difficulty << " code.\"\n";
}

bool PlayGame(int Difficulty)
{
    // If for level difficulty that changes text introduction per level
    if (Difficulty == 1)
    {
        LevelOne(Difficulty);
    }
    else if (Difficulty == 2)
    {
        LevelTwo(Difficulty);
    }
    else if (Difficulty == 3)
    {
        LevelThree(Difficulty);
    }
    else if (Difficulty == 4)
    {
        LevelFour(Difficulty);
    }
    else
    {
        LevelFive(Difficulty);
    }

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and product to terminal
    std::cout << "\n";
    std::cout << "+ There are 3 numbers in the code."
                 "\n";
    std::cout << "+ The codes add-up to: " << CodeSum << "\n";
    std::cout << "+ The codes multiply to give: " << CodeProduct << "\n";

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if player guess is correct or not
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n***Correct Entry. Keep Going!!***";
        return true;
    }
    else
    {
        std::cout << "***Incorrect Entry. Please try again***";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // Create a new random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel) // Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();  // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    std::cout << "\n***Upon entering the final code, you hear a click.  The door leads to a hallway lined with doors...and glowing terminals.....***";
    return 0;
}