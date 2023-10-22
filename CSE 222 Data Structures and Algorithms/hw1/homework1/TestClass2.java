package homework1;


public class TestClass2 {
    
    
    public static void main(String[] args){

        System.out.printf("\n\nStep 1...Creating accounts...");
        Account gizemsungu = new Account(0,"Gizem Süngü","01.02.1995","Izmir");
        Account sibelgulmez = new Account(1,"Sibel Gülmez","07.05.1996","Gebze");
        Account gokhankaya = new Account(2,"Gökhan Kaya","21.10.1990","Darıca");

        System.out.printf("\n\n\nStep 2...");
        sibelgulmez.login();

        System.out.printf("\n\n\nStep 3... Sharing two posts...");
        sibelgulmez.addPost(0,"I like Java.");
        sibelgulmez.addPost(1,"Java is better than coffee");

        System.out.printf("\n\n\nStep 4...Following gizemsungu and gokhankaya...");
        sibelgulmez.follow(gizemsungu);
        sibelgulmez.follow(gokhankaya);

        System.out.printf("\n\n\nStep 5...");  
        sibelgulmez.logout();

        System.out.printf("\n\n\nStep 6...");
        gokhankaya.login();

        System.out.printf("\n\n\nStep 7...");
        gokhankaya.viewProfile(sibelgulmez);

        System.out.printf("\n\n\nStep 8...");
        gokhankaya.viewPosts(sibelgulmez);

        System.out.printf("\n\n\nStep 9...");
        gokhankaya.addLike(0, sibelgulmez, 0);

        System.out.printf("\n\n\nStep 10...");
        gokhankaya.addComment(1, sibelgulmez, 0, "me too!");
        //gokhankaya.viewInteractions(sibelgulmez);
        gokhankaya.addComment(2, sibelgulmez, 1,"Absolutely I agree");

        System.out.printf("\n\n\nStep 11...");
        gokhankaya.follow(sibelgulmez);
        gokhankaya.follow(gizemsungu);

        System.out.printf("\n\n\nStep 12...");
        gokhankaya.sendMessage(0, gizemsungu, "This homework is too easy");

        System.out.printf("\n\n\nStep 13...");
        gokhankaya.logout();

        System.out.printf("\n\n\nStep 14...");
        gizemsungu.login();

        System.out.printf("\n\n\nStep 15...Checking outbox...");
        gizemsungu.checkOutbox();

        System.out.printf("\n\n\nStep 16...Checking inbox...");
        gizemsungu.checkInbox();

        System.out.printf("\n\n\nStep 17...");
        gizemsungu.viewInbox();
        //gizemsungu.viewOutbox();

        System.out.printf("\n\n\nStep 18...");
        gizemsungu.viewProfile(sibelgulmez);

        System.out.printf("\n\n\nStep 19...");
        gizemsungu.viewPosts(sibelgulmez);

        System.out.printf("\n\n\nStep 20...");
        gizemsungu.viewInteractions(sibelgulmez);

        System.out.printf("\n\n\nStep 21...");
        gizemsungu.addLike(3, sibelgulmez, 0);

        System.out.printf("\n\n\nStep 22...");
        gizemsungu.viewInteractions(sibelgulmez);

        System.out.printf("\n\n\nStep 23...");
        gizemsungu.addPost(2, "The Java: no nice frameworks, just horrifying definitions and pain.");

        System.out.printf("\n\n\nStep 24...");
        gizemsungu.addPost(3, "Everybody is chill until StackOverflow says that you are the first one to ask this question.");

        System.out.printf("\n\n\nStep 24...");
        gizemsungu.logout();

        System.out.printf("\n\n\nStep 25...");
        sibelgulmez.login();

        System.out.printf("\n\n\nStep 26...");
        sibelgulmez.viewProfile(gizemsungu);

        System.out.printf("\n\n\nStep 27...");
        sibelgulmez.addLike(4, gizemsungu, 3);

        System.out.printf("\n\n\nStep 28...");
        sibelgulmez.logout();

        System.out.printf("\n\n\nStep 29...");
        gokhankaya.login();

        System.out.printf("\n\n\nStep 30...");
        gokhankaya.viewProfile(gizemsungu);

        System.out.printf("\n\n\nStep 31...");
        gokhankaya.addComment(5, gizemsungu, 3, "Nice!");

        System.out.printf("\n\n\nStep 32...");
        gokhankaya.sendMessage(1, gizemsungu, "Hello!");

        System.out.printf("\n\n\nStep 33...");
        gokhankaya.logout();

        System.out.printf("\n\n\nStep 34...");
        gizemsungu.login();

        System.out.printf("\n\n\nStep 35...");
        gizemsungu.viewProfile(gizemsungu);

        System.out.printf("\n\n\nStep 36...");
        gizemsungu.viewInbox();

        System.out.printf("\n\n\nStep 37...An attempt will be made to view the profile from the sibel account that is not logged in.");
        sibelgulmez.viewProfile(gokhankaya);

    }
}
