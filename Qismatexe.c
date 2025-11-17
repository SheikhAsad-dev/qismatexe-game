#include <stdio.h>
#include <windows.h>
// declaring all the functions first
void DelayText(const char *s, int delay);
void ColorText(const char *s, int color, int delay);
void intro();
void scene1_widow();
void scene2_detective();
void scene3_memory(); 
void scene4_mentor();
void scene5_criminal();
void scene6_confrontation();
void calculateEnding();

// scoring variables
int nihilism_score = 0, absurdism_score = 0, power_score = 0;

// story choice variables
int widow_choice, philosophy_choice, sister_choice, mentor_choice, criminal_choice, ending_choice;

int main()
{	
	int tryAgain = 1;
	while (tryAgain)
	{
		//reset scores for try again
		nihilism_score = absurdism_score = power_score = 0;
		system("pause"); //pauses the screen 
		system("cls"); //clears output screen
		// calling all the functons
		intro();
		scene1_widow();
		scene2_detective();
		scene3_memory();
		scene4_mentor();
		scene5_criminal();
		scene6_confrontation();
		calculateEnding();
		
		DelayText("Do you want to play again? (1 for Yes, 0 for No): ", 50);
		scanf("%d", &tryAgain);
	}
	return 0;
}

void DelayText(const char *text, int delay) //used for type writer effect
{
	while (*text) //'\0' ascii value is 0
	{
		putchar(*text++); //printing character
		fflush(stdout); //used to flush the character 
		Sleep(delay); //pauses the screen
	}
}  

void ColorText(const char *text, int color, int delay)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); //function to take color
	DelayText(text, delay); //send colored text to DelayText function above
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //7 is default white resets the color before ending function
} 

void intro()	
{
	ColorText("\"We are the stories we choose to remember.\"\n", 11, 50);
	Sleep(1000);
	DelayText("You are Dr. Klein Morretti - founder of MemTech Industries.\n", 40);
	DelayText("A Neurosurgeon. A Visionary. A Memory Architect who erases pain by editing traumatic memories.\n", 40);
    DelayText("Your clinic, \"The Vault\" stands as a beacon of hope for the broken-hearted.\n", 40);
    DelayText("People seek you to be freed from the burdens of their past. You offer them - \n", 40);
    ColorText("a chance to rewrite their own stories.\n\n", 13, 40);
    
    DelayText("But beneath the surface of this technological miracle lies a dark truth.\n", 40);
    DelayText("Every memory you erase creates ripples in the fabric of human experience.\n", 40);
    DelayText("Some call you a savior. Others whisper that you're playing God.\n\n", 40);
	
    DelayText("Tonight, as rain streaks down your office window you prepare for another session.\n", 40);
    
    Sleep(1000);
	system("pause");
	return;
}

void scene1_widow()
{
	system("cls");
	ColorText("Patient #47 - The Widow.\n", 10, 40);
	DelayText("A pale woman sits before you, trembling.\nHer voice cracks with grief.\n", 40);
	DelayText("Her file glows on your tablet: \"Husband deceased - car accident 3 months ago.\n", 40);
    DelayText("Acute traumatic grief. Severe depression. Multiple suicide attempts.\"\n\n", 40);
    
	ColorText("Dr. Moretti... Erase Him... please. I don't want to remember him, she says.\n", 12, 40);
	ColorText("The weight of her request hangs heavy in the sterile air.\n", 15, 40);
    DelayText("What do you do?\n\n", 40);
    
    ColorText("1. Erase only the trauma - preserve the love, remove the pain\n", 14, 20);
    ColorText("2. Erase her husband entirely - complete memory extraction\n", 14, 20);
    ColorText("3. Erase her capacity to love again - prevent future suffering\n", 14, 20);
	ColorText("Enter your choice: ", 14, 20);
	scanf("%d", &widow_choice);
	
	switch (widow_choice)
	{
		case 1:
            DelayText("\nYou carefully target only the traumatic associations.\n", 40);
            DelayText("She smiles faintly through tears. \"I can remember our wedding day\n", 40);
            DelayText("without feeling like I'm being torn apart.\" Healing comes... but sorrow lingers.\n", 40);
            ColorText("\n\"The pain gives the memory meaning.\"\n", 8, 40);
            absurdism_score += 2;
            break;
        case 2:
            DelayText("\nThe procedure is thorough, precise. When she wakes, her eyes are calm - \n", 40);
            DelayText("too calm. \"There's an empty space where something important used to be,\n", 40);
            DelayText("but I don't know what.\" Love gone. Grief gone. Everything gone.\n", 40);
            ColorText("\n\"Nothing really matters in the end.\"\n", 8, 40);
            power_score += 2;
            break;
        case 3:
            DelayText("\nYou rewrite her emotional core. She becomes peaceful, detached.\n", 40);
            DelayText("Like marble carved into calm. But her eyes lack the warmth that makes us human.\n", 40);
            ColorText("\n\"I have the power to reshape human experience.\"\n", 8, 40);
            break;
		default:
			DelayText("\nSilence fills the room...\n", 40);		
	}
	system("pause");
	return;
}

void scene2_detective()	
{
	system("cls");
	ColorText("Agent Vera Cross steps into your office\n", 10, 40);
    DelayText("\"You are not healing them - you are rewriting them,\" she says coldly.\n", 40);
    DelayText("How do you justify yourself?\n\n", 40);
    
    ColorText("1. I'm giving people peace - they come to me for help\n", 14, 20);
    ColorText("2. Trauma is a disease. I am the cure - this is modern medicine\n", 14, 20);
    ColorText("3. Memories are illusions - why cling to painful ones?\n", 14, 20);
    ColorText("Enter your choice: ", 14, 20);
    scanf("%d", &philosophy_choice);
    
    switch(philosophy_choice) {
    	case 1:
    		ColorText("\"To live without hope is to cease to live.\"\n", 8, 40);
    		absurdism_score += 2;
    		break;
    	case 2:
    		ColorText("\"Power is only needed for punishment.\"\n", 8, 40);
    		power_score += 3;
    		break;
    	case 3:
    		ColorText("\"In the universe, nothing really matters.\"\n", 8, 40);
    		nihilism_score += 3;
    		break;
	}
	
    system("pause");
    return;
}

void scene3_memory()	
{
    system("cls");
    DelayText("That night... the Vault hums with old data.\n", 40);
    ColorText("A familiar voice echoes in your mind.\n", 8, 40);
    ColorText("\"You could not save me... you erased me.\"\n\n", 8, 40);
    
    DelayText("Your sister's face appears on the monitor - young, smiling, forever 17.\n", 40);
    DelayText("The accident that took her was too painful to bear. So you did what you do best.\n", 40);
    DelayText("You edited the memory. But some ghosts refuse to stay buried.\n\n", 40);
	
	ColorText("1. Erase this memory\n", 14, 20);
    ColorText("2. Keep it - even if it hurts\n", 14, 20);
    ColorText("Enter your choice: ", 14, 20);
    scanf("%d", &sister_choice);

    if(sister_choice == 1) {
        DelayText("\nYou initiate the final memory wipe. The ghost in the machine fades.\n", 40);
        DelayText("Silence returns to the Vault. Perfect, empty silence.\n", 40);
        ColorText("\"What doesn't kill me makes me stronger.\"\n", 8, 40);
        power_score += 3;
        nihilism_score +=2;
    } else {
        DelayText("\nYou let her memory burn inside you - painfully, beautifully alive.\n", 40);
        DelayText("Tears you haven't felt in years stream down your face.\n", 40);
        ColorText("\"Suffering is the sole origin of consciousness.\"\n", 8, 40);
        absurdism_score += 2;
    }
    system("pause");
}

void scene4_mentor()
{
	system("cls");
	ColorText("Unexpected Visit\n", 10, 40);
	DelayText("Dr. Dunn Smith, your old mentor, appears at your door.\n", 40);
	ColorText("\"Klein, I've seen what you're doing. This isn't medicine - this is playing God!\"\n", 15, 40);
	DelayText("He looks at you with deep concern and disappointment.\n\n", 40);
	
    ColorText("1. \"I'm healing pain no one else can\" - defend your methods\n", 14, 20);
    ColorText("2. \"They come to me willingly\" - emphasize patient choice\n", 14, 20);
    ColorText("3. \"Sometimes destruction is a form of creation\" - philosophical argument\n", 14, 20);
	scanf("%d", &mentor_choice);
	
	switch(mentor_choice) {
		case 1:
			DelayText("\n\"At what cost?\" he whispers. \"You're making them less human.\"\n", 40);
			ColorText("\"The mystery of human existence lies not in just staying alive.\"\n", 8, 40);
			absurdism_score += 2;
			break;
		case 2:
			DelayText("\n\"They're desperate!\" he argues. \"You prey on their weakness!\"\n", 40);
			ColorText("\"It's often safer to be in chains than to be free.\"\n", 8, 40);
			power_score += 2;
			break;
		case 3:
			DelayText("\nHe shakes his head sadly. \"You've lost your way, my friend.\"\n", 40);
			ColorText("\"He who fights with monsters should see to it that he himself does not become a monster.\"\n", 8, 40);
			nihilism_score += 2;
			break;
	}
	
	ColorText("\nHe leaves with a heavy heart, whispering: \"Remember your oath.\"\n", 15, 40);
	system("pause");
}

void scene5_criminal()	
{
    system("cls");
    ColorText("Patient #52 - A convicted murderer seeking mercy.\n",10, 40);
    DelayText("He sits before you, hands shaking, eyes haunted by his own actions.\n", 40);
    ColorText("\"Erase my guilt. Let me start again,\" he begs.\n", 15, 40);
    DelayText("\"The faces... I see them every night. The blood... the screams...\"\n\n", 40);
    
    DelayText("Suddenly, the door bursts open. Cross and her team storm in.\n", 40);
    ColorText("\"He doesn't deserve peace! He needs to face what he's done!\"\n\n", 12, 40);
   
    ColorText("1. Erase his guilt - grant his request despite the consequences\n", 14, 20);
    ColorText("2. Increase his guilt - make him feel his victims' pain more deeply\n", 14, 20);
    ColorText("3. Replace guilt with empathy - transform his remorse into understanding\n", 14, 20);
    ColorText("Enter your choice: ", 14, 20);
    scanf("%d", &criminal_choice);

    switch(criminal_choice) {
        case 1: 
			DelayText("\nHe smiles like a child - pure, empty.\n", 40);
			ColorText("\"If there is no God, then everything is permitted.\"\n", 8, 40);
			nihilism_score += 2;
			break;
        case 2: 
			DelayText("\nHe collapses, whispering for forgiveness.\n", 40);
			ColorText("\"He must face his absurd existence.\"\n", 8, 40);
			absurdism_score += 2;
			break;
        case 3: 
			DelayText("\nHe weeps... and promises to make amends.\n", 40);
			ColorText("\"To go wrong in one's own way is better than to go right in someone else's.\"\n", 8, 40);
			power_score += 2;
			break;
    }
    system("pause");
}

void scene6_confrontation()	
{
    system("cls");
    DelayText("The Vault glows - billions of memories suspended in light.\n", 40);
    DelayText("Alarms blare through the corridors of MemTech Industries.\n", 40);
    ColorText("Agent Vera Cross stands at the center, her team securing the perimeter.\n", 10, 40);
    DelayText("She turns to face you, her expression a mixture of pity and determination.\n\n", 40);
    
    ColorText("\"It's over, Klein. We have evidence of everything.\"\n", 12, 40);
    DelayText("She gestures at the swirling lights around you.\n", 40);
    ColorText("\"You're not healing people - you're rewriting them. Creating perfect, empty shells.\"\n", 12, 40);
    DelayText("\"Is this what you wanted? To play God with human souls?\"\n\n", 40);
    
    DelayText("You feel the weight of every choice you've made. Every memory altered.\n", 40);
    DelayText("Every life changed. The power here is absolute.\n", 40);
    
    ColorText("The future of human memory rests in your hands. What do you do?\n\n", 14, 40);
    
    ColorText("1. Let it be - Nothing matters anyway. Surrender to the meaninglessness\n", 14, 20);
    ColorText("2. Destroy the Vault - Free everyone, return their memories and pain\n", 14, 20);
    ColorText("3. Rewrite the world - Become the ultimate architect of human experience\n", 14, 20);
    ColorText("Enter your choice: ", 14, 20);
    scanf("%d", &ending_choice);

    //final choice gives big score boost
    switch(ending_choice) 
	{
        case 1: 
            nihilism_score += 5;
            DelayText("\nYou raise your hands slowly. \"I surrender,\" you say calmly.\n", 40);
			ColorText("\"In the face of absurdity, I choose nothing.\"\n", 8, 40);
            break;
        case 2: 
            absurdism_score += 5;
            DelayText("\nYour fingers fly across the control panel.The system screams warnings\n", 40);
            DelayText("Cross watches in awe as you sacrifice your life's work.\n", 40);
            ColorText("\"The struggle itself gives life meaning.\"\n", 8, 40);
            break;
        case 3: 
            power_score += 5;
			DelayText("You reach for the master control interface, ready to rewrite reality itself.\n", 40);
            ColorText("\"Stop him!\" Cross shouts as her team advances.\n", 12, 40);
			ColorText("\"I am become Death, the destroyer of worlds.\"\n", 8, 40);
            break;
        default: 
            DelayText("Silence consumes the Vault.\n", 40);
    }
    DelayText("\n\nThe confrontation reaches its climax...\n", 40);
	system("pause");
	return;
}
void calculateEnding()
{
    system("cls");
    ColorText("FINAL DESTINY\n", 12, 50);
    DelayText("Time passes... your story finds its conclusion.\n\n", 40);
    
    // Show final scores
    ColorText("Your Path:\n", 14, 40);
    printf("Acceptance: %d\n", nihilism_score);
    printf("Redemption: %d\n", absurdism_score);
    printf("Control: %d\n", power_score);
    printf("\n");
    
    // Determine ending based on scores
    if (nihilism_score >= absurdism_score && nihilism_score >= power_score) 
    {
        ColorText("ENDING: THE EMPTY SAVIOR\n", 12, 50);
        // final choice if it is matching then if block
        if (ending_choice == 1) {
            DelayText("You surrender peacefully. At trial, patients testify about the emptiness you gave them.\n", 40);
            DelayText("You wanted to help, but realize you only exchanged pain for nothingness.\n", 40);
            ColorText("\"In trying to fix suffering, I erased what makes us human.\"\n", 13, 40);
        } else {
            DelayText("As they arrest you, you feel no regret. You tried to heal the world,\n", 40);
            DelayText("but now see that pain and meaning cannot be separated.\n", 40);
            ColorText("\"We chase meaning in a universe that offers none.\"\n", 13, 40);
        }
        
        DelayText("In prison, you find peace in the truth: nothing matters.\n", 40);
        ColorText("\"The universe is a tale told by an idiot, full of sound and fury, signifying nothing.\"\n", 8, 40);
        DelayText("- William Shakespeare\n\n", 30);
        ColorText("You are free of illusions, carrying the beautiful, terrible truth.\n", 10, 40);
    }
    else if (absurdism_score >= nihilism_score && absurdism_score >= power_score) 
    {
        ColorText("ENDING: THE ABSURD HERO\n", 12, 50);
        if (ending_choice == 2) {
            DelayText("As the Vault collapses, you help Cross evacuate her team.\n", 40);
            DelayText("Memories flood back to humanity - pain and joy returning in equal measure.\n", 40);
            DelayText("People rediscover what it means to be truly human, flaws and all.\n\n", 40);
            DelayText("You surrender willingly, at peace with your choice.\n", 40);
        } else {
            DelayText("The destruction of the Vault becomes your redemption.\n", 40);
            DelayText("Though arrested, you're hailed as a hero who returned humanity to itself.\n", 40);
            DelayText("Your sacrifice reminds the world that pain is part of what makes us human.\n\n", 40);
        }
        ColorText("\"Man is the only creature who refuses to be what he is.\"\n", 8, 40);
        DelayText("- Albert Camus\n", 30);
        Sleep(500);
        ColorText("In your cell, you write your memoirs. The pain feels like freedom.\n", 10, 40);
    }
    else 
    {
        ColorText("ENDING: THE MEMORY ARCHITECT\n", 12, 50);
        if (ending_choice == 3) {
            DelayText("You rewrite Cross and her team first. Their weapons drop as new memories form.\n", 40);
            DelayText("They become your loyal followers, convinced of your divine purpose.\n", 40);
            DelayText("One by one, you reshape the world into a paradise of perfect contentment.\n\n", 40);
        } else {
            DelayText("Despite your surrender, your technology lives on.\n", 40);
            DelayText("Governments adopt your methods, creating a world without conflict or pain.\n", 40);
            DelayText("You watch from your gilded cage as humanity becomes peacefully, perfectly empty.\n\n", 40);
        }
        ColorText("\"Taking a new step, uttering a new word, is what people fear most.\"\n", 8, 40);
        DelayText("- Fyodor Dostoevsky\n\n", 30);
        Sleep(500);
        ColorText("You become the lonely god of a happy, hollow world.\n", 10, 40);
    }
    
    DelayText("\n\nYour story ends here...\n", 40);
    ColorText("What is a game but life condensed into meaningful patterns?\n", 4, 50);
	//when players finish your story, they haven't just completed a game
	//they've lived through a condensed philosophical journey that might change how they see their actual lives.
    system("pause");
}