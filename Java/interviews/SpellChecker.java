package interviews;

//This is the text editor interface. 
//Anything you type or change here will be seen by the other person in real time.

//You have a dictionary of words. You need to implement a spellchecker that returns the correct word for an input word.

//The spellchecker only handles the following two class of spelling mistakes - 
//1) Capitalization
//<dictionary: {yellow, radish}, input: yelloW, output: yellow>, 
//<dictionary: {Yellow, radish}, input: yelloW, output: Yellow>


//2) Vowels (letters in the set {a,e,i,o,u}) mixed up - consonants are in the correct order, but one or more vowels in the input word is/are not the same as the vowels in the corresponding dictionary word
//<dictionary: {yellw, radish}, input: yollow, output: yellow>
//<dictionary: {yellow, radish}, input: redosh, output: radish>, etc
//
//"yellow" <=> "y_ll_w" => "yellow"
//
//ayllow
//26+26 possible letters in a word
//
import java.util.*;

public class SpellChecker {
 private HashMap<String, String> dictionary = new HashMap<String, String>();
 
 public SpellChecker(String[] strs) {
     insertIntoDictionary(strs);
 }
 
 public void insertIntoDictionary (String[] strs) {
     for(int i = 0; i < strs.length; i++) {
         if(!dictionary.containsKey(strs[i].toLowerCase())) {
             dictionary.put(strs[i].toLowerCase(), strs[i]);
         }
     }
 }

 public String lookupDict(String target) {
     if (dictionary.containsKey(target.toLowerCase())) return dictionary.get(target.toLowerCase());
     return null;        
 }
 
 public String spellChecker(String input) {
     return lookupDict(input);
 }
 
 public static void main(String[] args) {
     SpellChecker sc = new SpellChecker(new String [] {"Yellow", "radish"});
     System.out.println("Spell checker output " + sc.spellChecker("yelloW"));
 }
}