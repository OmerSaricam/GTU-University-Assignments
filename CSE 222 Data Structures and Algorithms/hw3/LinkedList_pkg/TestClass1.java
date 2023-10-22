package LinkedList_pkg;




public class TestClass1 {
    
    
    public static void main(String[] args){

        long startTime = System.nanoTime();

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

        System.out.printf("\n\n\n");

        long endTime = System.nanoTime();
        long elapsedTime = endTime - startTime;
        System.out.println("Elapsed time: " + elapsedTime + " ns\n\n");
    }
}
