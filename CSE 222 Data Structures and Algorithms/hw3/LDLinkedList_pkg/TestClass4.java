package LDLinkedList_pkg;


public class TestClass4 {
    
    
    public static void main(String[] args){

        long startTime = System.nanoTime();

        System.out.printf("\n\nStep 1...Creating accounts...");
        Account adamsmith = new Account(0,"Adam Smith","01.02.1723","Edinburgh");
        Account markopolo = new Account(1,"Marco Polo","01.02.1995","Venice");
        Account ibnibattuta = new Account(2,"İbn Battuta","01.02.1995","Tanca");
        Account evliyacelebi = new Account(3,"Evliya Çelebi","01.02.1995","Unkapanı");
        Account lafontaine = new Account(4,"La Fontaine","01.02.1995","Paris");
        Account elonmusk = new Account(5,"Elon Musk","01.02.1995","Izmir");
        Account henryford = new Account(6,"Henry Ford","01.02.1995","Michigan");
        Account robinsoncrusoe = new Account(7,"Robinson Crusoe","01.02.1995","London");
        Account sherlockholmes = new Account(8,"Sherlock Holmes","01.02.1995","Çorum");
        Account anaksimandros = new Account(9,"Anaksimandros","01.02.1995","Miletus");


        System.out.printf("\n\nStep 2...");
        markopolo.login();

        System.out.printf("\n\nStep 3...");
        markopolo.addPost(0, "There are unicorns in China");
        markopolo.addPost(1,"I didn't even tell half of what I saw because no one would believe me");
        markopolo.addPost(2,"We are like buddy with the Mongol emperor Kublai Khan, close enough to use the same toothpick");
        markopolo.addPost(3,"Spirits roam in the Gobi Desert, friends, if you want to go, don't go without consulting the locals.");

        System.out.printf("\n\nStep 4...");
        markopolo.follow(evliyacelebi);
        markopolo.logout();

        System.out.printf("\n\nStep 5...");
        evliyacelebi.login();

        System.out.printf("\n\nStep 6...");
        evliyacelebi.addComment(0, markopolo, 3, "There's worse than this. One day, while I was in Bulgaria, while I was resting at night, a woman entered the place where I was resting and the woman, who was messy, started to say something in a different language. After some time passed, 7 children gathered around the woman. After performing some kind of ritual, the children turned into chickens.");

        System.out.printf("\n\nStep 7...");
        evliyacelebi.addLike(1, markopolo, 0);

        System.out.printf("\n\nStep 8...");
        evliyacelebi.addLike(2, markopolo, 1);

        System.out.printf("\n\nStep 9...");
        evliyacelebi.showActions();

        System.out.printf("\n\nStep 10...");
        evliyacelebi.follow(anaksimandros);
        evliyacelebi.follow(markopolo);
        evliyacelebi.follow(elonmusk);
        evliyacelebi.follow(adamsmith);
        evliyacelebi.viewProfile(evliyacelebi);

        System.out.printf("\n\nStep 11...");
        evliyacelebi.addComment(3, markopolo, 0, "You're probably talking about rhinos, man");     

        System.out.printf("\n\nStep 12...");
        evliyacelebi.addComment(4, markopolo, 2, "Yes that's true because I'm also the emperor of Japan, I witnessed it");
        evliyacelebi.addComment(5, markopolo, 2, "You didn't even go east of Urumqi");
        evliyacelebi.addComment(6, markopolo, 2, "That's enough bullshit, I'm unfollowing you.");

        System.out.printf("\n\nStep 13...");
        evliyacelebi.unfollow(markopolo);
        evliyacelebi.unfollow(anaksimandros);
        evliyacelebi.viewProfile(evliyacelebi);


        System.out.printf("\n\nStep 14...");
        evliyacelebi.viewInteractions(markopolo);

        System.out.printf("\n\nStep 15...");
        evliyacelebi.unlike(markopolo, 0);

        System.out.printf("\n\nStep 16...");
        evliyacelebi.uncomment(markopolo, 2, 2);

        System.out.printf("\n\nStep 17...");
        evliyacelebi.showActions();
        
        System.out.printf("\n\nStep 18...");
        evliyacelebi.logout();

        System.out.printf("\n\nStep 19...");
        markopolo.login();

        System.out.printf("\n\nStep 20...");
        markopolo.viewInteractions(markopolo);

        System.out.printf("\n\nStep 21...");
        markopolo.addPost(4, "O awliya celebi! If you unfollow me, I will block you too. Why did you delete your comment? Because you know I went east of Urumqi");

        System.out.printf("\n\nStep 22...");
        markopolo.blockUser(evliyacelebi);

        System.out.printf("\n\nStep 23...");
        markopolo.follow(lafontaine);
        markopolo.follow(henryford);
        markopolo.follow(ibnibattuta);

        System.out.printf("\n\nStep 24...");
        markopolo.showActions();

        System.out.printf("\n\nStep 25..");
        markopolo.logout();

        System.out.printf("\n\nStep 27...");
        adamsmith.login();

        System.out.printf("\n\nStep 28...");
        adamsmith.follow(robinsoncrusoe);
        adamsmith.follow(sherlockholmes);
        adamsmith.follow(evliyacelebi);

        System.out.printf("\n\nStep 29...");
        adamsmith.viewPosts(markopolo);

        System.out.printf("\n\nStep 30...");
        adamsmith.addComment(6, markopolo, 4, "These behaviors is not becoming of grown men like you");

        System.out.printf("\n\nStep 31...");
        adamsmith.sendMessage(0, evliyacelebi, "Hey bro, you have blocked by Marko Polo! Marko Polo seems to be upset with you.");

        System.out.printf("\n\nStep 32...");
        adamsmith.logout();

        System.out.printf("\n\nStep 33...");
        evliyacelebi.login();

        System.out.printf("\n\nStep 34...");
        evliyacelebi.viewInbox();

        System.out.printf("\n\nStep 35...Evliya Çelebi is trying to view Marco Polo's profile...");
        evliyacelebi.viewProfile(markopolo);

        System.out.printf("\n\nStep 36...Evliya Çelebi is trying to view Marco Polo's interactions...");
        evliyacelebi.viewInteractions(markopolo);

        System.out.printf("\n\nStep 37...");
        evliyacelebi.sendMessage(1, adamsmith, "I think you're right. My words must have been a bit harsh. I was just messing around.");

        System.out.printf("\n\nStep 38...");
        evliyacelebi.logout();

        System.out.printf("\n\nStep 39...");
        markopolo.login();

        System.out.printf("\n\nStep 40...");
        markopolo.viewInteractions(markopolo);

        System.out.printf("\n\nStep 41...");
        markopolo.unblockUser(evliyacelebi);

        System.out.printf("\n\nStep 42...Marko Polo is trying to message Evliya Çelebi without following him. However, by blocking him, he also ended up unfollowing him...");
        markopolo.sendMessage(2, evliyacelebi, "I got angry all of a sudden and couldn't resist blocking you when you unfollowed me. I'm sorry about that");

        System.out.printf("\n\nStep 43...");
        markopolo.follow(evliyacelebi);

        System.out.printf("\n\nStep 44...");
        markopolo.sendMessage(2, evliyacelebi, "I got angry all of a sudden and couldn't resist blocking you when you unfollowed me. I'm sorry about that");

        System.out.printf("\n\nStep 45...");
        markopolo.showActions();

        System.out.printf("\n\nStep 46...");
        markopolo.logout();

        System.out.printf("\n\nStep 47...");
        evliyacelebi.login();

        System.out.printf("\n\nStep 48...");
        evliyacelebi.viewProfile(markopolo);

        System.out.printf("\n\n\n");


        long endTime = System.nanoTime();
        long elapsedTime = endTime - startTime;
        System.out.println("Elapsed time: " + elapsedTime + " ns\n\n");






    }
    
}    