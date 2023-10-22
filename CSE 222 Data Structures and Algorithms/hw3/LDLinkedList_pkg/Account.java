package LDLinkedList_pkg;



/**
 * The Account class represents a user account in a social media application.
 * It stores information such as the user's username, birthdate, location,
 * posts, followers, and following. The class also provides methods to
 * interact with the user account such as logging in, logging out, adding
 * posts, following and unfollowing other accounts, and blocking and
 * unblocking accounts.
 */
public class Account {
    
    /**
     * The unique id of the account.
     */
    private final int accountId;

    /**
     * The username of the account.
     */
    private String username;

    /**
     * The birthdate of the account holder.
     */
    private String birthdate;

    /**
     * The location of the account holder.
     */
    private String location;

    /**
     * An LDLinkedList of Post objects representing the posts made by the account holder.
     */
    private LDLinkedList<Post> posts = new LDLinkedList<Post>();

    /**
     * The number of posts made by the account holder.
     */
    private int post_number = 0;

    /**
     * An LDLinkedList of Account objects representing the accounts followed by the account holder.
     */
    private LDLinkedList<Account> following = new LDLinkedList<Account>();

    /**
     * The number of accounts followed by the account holder.
     */
    private int following_number = 0; 

    /**
     * An LDLinkedList of Account objects representing the accounts following the account holder.
     */
    private LDLinkedList<Account> followers = new LDLinkedList<Account>();

    /**
     * The number of accounts following the account holder.
     */
    private int followers_number = 0;

    /**
     * An LDLinkedList of Message objects representing the messages received by the account holder.
     */
    private LDLinkedList<Message> inbox = new LDLinkedList<Message>();

    /**
     * The number of messages received by the account holder.
     */
    private int inbox_msg_number = 0;

    /**
     * An LDLinkedList of Message objects representing the messages sent by the account holder.
     */
    private LDLinkedList<Message> outbox = new LDLinkedList<Message>();

    /**
     * The number of messages sent by the account holder.
     */
    private int outbox_msg_number = 0;

    /**
     * An LDLinkedList of Account objects representing the accounts blocked by the account holder.
     */
    private LDLinkedList<Account> blocked_users = new LDLinkedList<Account>();

    /**
     * The number of accounts blocked by the account holder.
     */
    private int blocked_users_number = 0;

    /**
     * A boolean indicating the login status of the account holder.
     */
    private boolean login_status = false; 

    /**
     * Action history of the account
     */
    private LDLinkedList<String> actions = new LDLinkedList<String>();


    /**
     * Constructs a new Account object with the given account id, username, birthdate and location.
     * 
     * @param accountId the unique id of the account
     * @param username the username of the account holder
     * @param birthdate the birthdate of the account holder
     * @param location the location of the account holder
     */
    public Account(final int accountId, String username, String birthdate, String location){
    
        this.accountId = accountId;
        this.username = username;
        this.birthdate = birthdate;
        this.location = location;

        System.out.printf("\nAn account with username %s has been created.",username);
    }

    /**
     * Returns the unique id of the account.
     * 
     * @return the unique id of the account
     */
    public int getAccountId(){
        return accountId;
    }

    /**
     * Returns the username of the account holder.
     * 
     * @return the username of the account holder
     */
    public String getUsername(){ 
        return username; 
    }

    /**
    Returns the birthdate of the account holder.
    @return the birthdate of the account holder
    */
    public String getBirthdate(){
        return birthdate;
    }

    /**
    Returns the location of the account holder.
    @return the location of the account holder
    */
    public String getLocation(){
        return location;
    }

    /**
    Returns an LDLinkedList of Post objects representing the posts made by the account holder.
    @return an LDLinkedList of Post objects representing the posts made by the account holder
    */
    public LDLinkedList<Post> getPost(){
        return posts;
    }
 
    /**   
    Returns the number of posts made by the account holder.
    @return the number of posts made by the account holder
    */
    public int getPost_number(){
        return post_number;
    }

    /**  
    Returns an LDLinkedList of Account objects representing the accounts followed by the account holder.
    @return an LDLinkedList of Account objects representing the accounts followed by the account holder
    */
    public LDLinkedList<Account> getFollowing(){
        return following;
    }

    /**
    Returns the number of accounts followed by the account holder.
    @return the number of accounts followed by the account holder
    */
    public int getFollowing_number(){
        return following_number;
    }

    /**
    Returns an LDLinkedList of Account objects representing the accounts following the account holder.
    @return an LDLinkedList of Account objects representing the accounts following the account holder
    */
    public LDLinkedList<Account> getFollowers(){
        return followers;
    }

    /**
    Returns the number of accounts following the account holder.
    @return the number of accounts following the account holder
    */
    public int getFollowers_number(){
        return followers_number;
    }

    /**
    Returns an LDLinkedList of Message objects representing the messages received by the account holder.
    @return an LDLinkedList of Message objects representing the messages received by the account holder
    */
    public LDLinkedList<Message> getInbox(){
        return inbox;
    }

    /**
    Returns the number of messages received by the account holder.
    @return the number of messages received by the account holder
    */
    public int getInbox_Msg_Number(){
        return inbox_msg_number;
    }

    /**
    Returns an LDLinkedList of Message objects representing the messages sent by the account holder.
    @return an LDLinkedList of Message objects representing the messages sent by the account holder
    */
    public LDLinkedList<Message> getOutbox(){
        return outbox;
    }

    /** 
    Returns the number of messages sent by the account holder.
    @return the number of messages sent by the account holder
    */
    public int getOutbox_Msg_Number(){
        return outbox_msg_number;
    }

    /**
    Returns an LDLinkedList of Account objects representing the accounts blocked by the account holder.
    @return an LDLinkedList of Account objects representing the accounts blocked by the account holder
    */
    public LDLinkedList<Account> getBlocked_Users(){
        return blocked_users;
    }

    /**
    Returns the number of accounts blocked by the account holder.
    @return the number of accounts blocked by the account holder
    */
    public int getBlocked_user_number(){
        return blocked_users_number;
    }
    
    /**
     * returns the action history of the account
     * @return the action history of the account
     */
    public LDLinkedList<String> getActions(){ 
        return actions;
    }

    /**
    Increments the number of messages received by the account holder.
    */
    public void incrementInboxMsgNumber(){ inbox_msg_number++; }

    /**
     * Logs in to the account.
     */
    public void login(){

        login_status = true;
        System.out.printf("\nLogging into an account (username: %s).",username);
    }

    /**
     * Logs out from the account.
     */
    public void logout(){

        if(login_status == true){
            login_status = false;
            System.out.printf("\nLogging out from account '%s'.",username);
        }

        else{
            System.out.printf("\nTo log out of the account, you must first log in");
        }
    }

    /**
     * Adds a new post to the account.
     *
     * @param postId the ID of the post
     * @param content the content of the post
     */
    public void addPost(final int postId, String content){
        
        if(login_status == false){
            System.out.printf("\nTo do this, you must first log into %s account.",username);
        }
        else{
            Post post_ = new Post(postId,accountId,content);
            posts.add(post_);
            post_number++; 

            System.out.printf("\nThe post has been shared: %s",content);
            actions.add("You shared a post: " + content);
        }
    }

    /**
     * Follows another account.
     *
     * @param account_ the account to be followed
     */
    public void follow(Account account_){
       
        if(login_status == false){
            System.out.printf("\nTo do this, you must first log into %s account.",username);
        }
        
        else{
            
            
            if(account_.isBlocked(this) == true){
               System.out.printf("\nYou cannot do this. This account has blocked you");
            }
            
            else{
                following.add(account_);
                account_.follower_process(this);
                following_number++;
                System.out.printf("\nYou are following %s",account_.getUsername());
                actions.add("You followed: " + account_.getUsername());
            }
        }
    }


    /**
     * Unfollow an followed account.
     *
     * @param account_ the account to be unfollowed
     */
    public void unfollow(Account account_){
       
        if(login_status == false){
            System.out.printf("\nTo do this, you must first log into %s account.",username);
        }
        
        else{
            
            if(account_.isBlocked(this) == true){
               System.out.printf("\nYou cannot do this. This account has blocked you");
            }
            
            else{

                for(int i=0 ; i< following_number; i++){

                    if(following.get(i).getAccountId() == account_.getAccountId()){
                        following.remove(i);
                        following_number--;
                        account_.unfollower_process(this);
                        System.out.printf("\nYou unfollowed %s",account_.getUsername());
                        actions.add("You unfollowed: " + account_.getUsername());
                        return;
                    }
                }

                System.out.printf("\nYou are not already following this account: %s",account_.getUsername());
                
            }
        }
    }


    /**
     * Processes follower requests for the account.
     *
     * @param account_ the account requesting to follow
     */
    public void follower_process(Account account_){  
        
        followers_number++;
        followers.add(account_);

        
    }


    /**
     * When this account is an unfollowed account, this method takes the necessary actions on this account, removes that account from followers
     *
     * @param account_ the account requesting to unfollow
     */
    public void unfollower_process(Account account_){  
        
        for(int i=0 ; i< followers_number; i++){

            if(followers.get(i).getAccountId() == account_.getAccountId()){
                followers.remove(i);
                followers_number--;
                return;
            }
        }
    }


    /**
     * Views the profile of another account.
     *
     * @param account_ the account whose profile is being viewed
     */
    public void viewProfile(final Account account_){
 

        if(login_status == false){
            System.out.printf("\nTo do this, you must first log into %s account.",username);
        }

        else{

            if(account_.isBlocked(this) == true){
                System.out.printf("\nYou cannot do this. This account has blocked you");
            }
             
            else{
                System.out.printf("\n\n...Viewing %s's profile...\n--------------------",account_.getUsername());
                
                System.out.printf("\nUser ID: %d",account_.getAccountId());
                System.out.printf("\nUsername: %s",account_.getUsername());
                System.out.printf("\nLocation: %s",account_.getLocation());
                System.out.printf("\nBirth Date: %s",account_.getBirthdate());
                
                System.out.printf("\n%s is following %d account(s) and has %d follower(s)",account_.getUsername(),account_.getFollowing_number(),account_.getFollowers_number());
                System.out.printf("\nThe followers of %s are: ",account_.getUsername());
                for(int i=0 ; i<account_.getFollowers_number(); i++){
                    System.out.printf(" %s, ",account_.getFollowers().get(i).getUsername());
                }
                System.out.printf("\n%s is following: ",account_.getUsername());
                for(int i=0 ; i<account_.getFollowing_number(); i++){
                    System.out.printf(" %s, ",account_.getFollowing().get(i).getUsername());
                }  
                    
                System.out.printf("\n%s has %d posts",account_.getUsername(),account_.getPost_number());
            }
            
        }
    }
    
    /**
     * This method allows an account to view the posts of another account.
     * @param account_ the account whose posts will be viewed
     */    
    public void viewPosts(Account account_){

        if(login_status == false){
            System.out.printf("\nTo do this, you must first log into %s account.",username);
        }

        else{
            if(account_.isBlocked(this) == true){
                System.out.printf("\nYou cannot do this. This account has blocked you");
            }
             
            else{
                System.out.printf("\n...Viewing %s 's posts...",account_.getUsername());
                
                for(int i=0 ; i<account_.getPost_number(); i++){
                    System.out.printf("\n(PostID: %d)  %s: %s",i,account_.getUsername(),account_.getPost().get(i).getContents());
                }
            }

        }
    }

    /**
     * This method allows an account to add a like to a post of another account.
     * @param interactionId the interaction ID. interactionId is given manually because static is forbidden
     * @param account_ the account whose post will be liked
     * @param postId the ID of the post to be liked
     */
    public void addLike(final int interactionId, Account account_,final int postId){
        
        if(login_status == false){
            System.out.printf("\nTo do this, you must first log into %s account.",username);
        }

        else{
            
            if(account_.isBlocked(this) == true){
                System.out.printf("\nYou cannot do this. This account has blocked you");
            }
             
            else{
                System.out.printf("\nLiking a post of %s...",account_.getUsername());
                for(int i = 0; i<account_.getPost_number(); i++){

                    if(account_.getPost().get(i).getPostId() == postId){
                        account_.getPost().get(i).liking_process(interactionId,accountId,this);
                        actions.add("You liked " + account_.getUsername() + "'s post. ID: " + postId );
                        return;
                    }
                }

                System.out.printf("\nThere is no such post. check the postID");
            }
        }
    }


    /**
     * This method allows an account unlike to a post of another account.
     * @param account_ the account whose post will be unliked
     * @param postId the ID of the post to be unliked
     */
    public void unlike(Account account_,final int postId){
        
        if(login_status == false){
            System.out.printf("\nTo do this, you must first log into %s account.",username);
        }
        else{
            
            if(account_.isBlocked(this) == true){
                System.out.printf("\nYou cannot do this. This account has blocked you");
            }
             
            else{
                System.out.printf("\nUnliking a post of %s...",account_.getUsername());
                for(int i = 0; i<account_.getPost_number(); i++){

                    if(account_.getPost().get(i).getPostId() == postId){
                        account_.getPost().get(i).unliking_process(this);
                        return;
                    }
                }

                System.out.printf("\nThere is no such post. check the postID");
            }
        }        
        
    }

    /**
     * This method allows an account to add a comment to a post of another account.
     * @param interactionId the interaction ID
     * @param account_ the account whose post will be commented on
     * @param postId the ID of the post to be commented on
     * @param content_ the content of the comment
     */
    public void addComment(final int interactionId, Account account_,final int postId, String content_){
        
        if(login_status == false){
            System.out.printf("\nTo do this, you must first log into %s account.",username);
        }
        else{
            
            if(account_.isBlocked(this) == true){
                System.out.printf("\nYou cannot do this. This account has blocked you");
            }
             
            else{
                System.out.printf("\nAdding a comment on a post of %s : %s...",account_.getUsername(),content_);
                for(int i = 0; i<account_.getPost_number(); i++){

                    if(account_.getPost().get(i).getPostId() == postId){
                        account_.getPost().get(i).commenting_process(interactionId,accountId,this,content_);
                        actions.add("You commented "+ account_.getUsername() + " 's post. Post ID: " + postId );
                        return;
                    }
                }
                System.out.printf("\nThere is no such post. check the postID");
            }
        }
    }


    /**
     * This method allows the account to delete his/her comment on a post.
     * @param account_ The owner of the post that you will delete the comment
     * @param postId ID of the post where the comment will be deleted
     * @param which_comment Information on which comment will be deleted
     */
    public void uncomment(Account account_,final int postId, final int which_comment){
        
        if(login_status == false){
            System.out.printf("\nTo do this, you must first log into %s account.",username);
        }
        else{
            
            if(account_.isBlocked(this) == true){
                System.out.printf("\nYou cannot do this. This account has blocked you");
            }
             
            else{
                System.out.printf("\nThe comment on the post of %s is being deleted.",account_.getUsername());
                for(int i = 0; i<account_.getPost_number(); i++){

                    if(account_.getPost().get(i).getPostId() == postId){
                        account_.getPost().get(i).uncommenting_process(this,which_comment);
                        return;
                    }
                }
                System.out.printf("\nThere is no such post. check the postID");
            }
        }
    }



    /**
     * Displays interactions on a specified Account's posts.
     * 
     * @param account_ the Account object whose posts' interactions are to be viewed
     */
    public void viewInteractions(Account account_){

        if(login_status == false){
            System.out.printf("\nTo do this, you must first log into %s account.",username);
        }

        else{
            
            if(account_.isBlocked(this) == true){
                System.out.printf("\nYou cannot do this. This account has blocked you");
            }
             
            else{
            
                System.out.printf("\nViewing %s's posts' interactions...\n----------------------",account_.getUsername());
                if(account_.getPost_number() == 0){
                    System.out.printf("\nThere is no interaction of %s",account_.getUsername());
                }

                else{

                    for(int i=0; i<account_.getPost_number(); i++){
                        
                        System.out.printf("\n(Post Id: %d) : %s",account_.getPost().get(i).getPostId(),account_.getPost().get(i).getContents());

                        if(account_.getPost().get(i).getLike_number() == 0){
                            System.out.printf("\nThe post has no like. Be the first to like");
                        }
                        else{
                            System.out.printf("\nThe post was liked by the following account(s): ");
                            for(int j = 0; j<account_.getPost().get(i).getLike().size(); j++){
                                System.out.printf(" %s,",account_.getPost().get(i).getLike().get(j).getAccount().getUsername());
                            }
                        }

                        if(account_.getPost().get(i).getComment_number() == 0){
                            System.out.printf("\nThe post has no comment. Make the first comment");
                        }

                        else{
                            System.out.printf("\nThe post has %d comment(s)... ",account_.getPost().get(i).getComment_number());
                            for(int j = 0; j<account_.getPost().get(i).getComment().size(); j++){
                                if(account_.getPost().get(i).getComment().get(j).getIsDeleted() == false){
                                    System.out.printf("\nComment %d: '%s' said '%s'",j+1,account_.getPost().get(i).getComment().get(j).getAccount().getUsername(), account_.getPost().get(i).getComment().get(j).getContent());
                                }
                            }                    
                        }

                        System.out.printf("\n-------------------------");
                    }
                }
            }
        }
    }


    /**
     * Sends a message to a specified Account.
     * 
     * @param messageId the ID of the message to be sent
     * @param account_ the Account object to send the message to
     * @param content the content of the message to be sent
     */    
    public void sendMessage(final int messageId,Account account_, String content){

        if(login_status == false){
            System.out.printf("\nTo do this, you must first log into %s account.",username);
        }
        
        else{
            
            if(account_.isBlocked(this) == true){
                System.out.printf("\nYou cannot do this. This account has blocked you");
            }
             
            else{
                int flag = 0;
                for(int i=0 ; i<following_number; i++){
                if(following.get(i).getAccountId() == account_.getAccountId()){ flag = 1; }
                }

                if(flag == 0){
                System.out.printf("\nYou must follow that account to send message!");
                }

                else{
                    System.out.printf("\nSending a message to %s...: %s",account_.getUsername(),content);
                    Message message_ = new Message(messageId,accountId,this,account_.getAccountId(),account_,content);

                    outbox.add(message_);
                    outbox_msg_number++;
                    account_.getInbox().add(message_); 
                    account_.incrementInboxMsgNumber();
                    actions.add("You sent message to: " + account_.getUsername());
                }

            }



        }
    }


    /**
     * Displays the number of messages in the outbox.
     */
    public void checkOutbox(){

        if(login_status == false){
            System.out.printf("\nTo do this, you must first log into %s account.",username);
        }

        else{
            System.out.printf("\nThere is/are %d message(s) in the outbox.",outbox_msg_number);
        }
    }

    /**
     * Displays the number of messages in the inbox.
     */
    public void checkInbox(){

        if(login_status == false){
            System.out.printf("\nTo do this, you must first log into %s account.",username);
        }

        else{
            System.out.printf("\nThere is/are %d message(s) in the inbox.",inbox_msg_number);
        }
    }

    /**
     * Displays the messages in the inbox.
     */
    public void viewInbox(){

        if(login_status == false){
            System.out.printf("\nTo do this, you must first log into %s account.",username);
        }

        else{
            
            System.out.printf("\n...Viewing inbox...");

            if( inbox_msg_number == 0){
                System.out.printf("\nThere is no inbox message");
            }

            else{

                for(int i=0; i<inbox_msg_number; i++){
                    System.out.printf("\n--------------------\n Message ID: %d \nFrom: %s \nTo: %s \nMessage: %s",inbox.get(i).getMessageIdd(),inbox.get(i).getSenderAcc().getUsername(),username,inbox.get(i).getContent() );
                }
            }
        }
    }

    /**
     * Displays the messages in the outbox.
     */
    public void viewOutbox(){

        if(login_status == false){
            System.out.printf("\nTo do this, you must first log into %s account.",username);
        }

        else{

            if( outbox_msg_number == 0){
                System.out.printf("\nThere is no outbox message");
            }

            else{

                for(int i=0; i<outbox_msg_number; i++){
                    System.out.printf("\n--------------------\n Message ID: %d \nFrom: %s \nTo: %s \nMessage: %s",outbox.get(i).getMessageIdd(),username, outbox.get(i).getSenderAcc().getUsername(),outbox.get(i).getContent() );
                }
            }
        }
    }

    /**
     * Checks if the given account is blocked.
     *
     * @param account the account to check if it's blocked
     * @return true if the account is blocked, false otherwise
     */
    public boolean isBlocked(Account account){

        for(int i=0; i<blocked_users_number; i++){

            if(blocked_users.get(i).getAccountId() == account.getAccountId()){
                return true;
            }
        }

        return false;
    }
    
    /**
     * Blocks the given account and adds it to the blocked users LDLinkedList
     *
     * @param account the account to block
     */
    public void blockUser(Account account){
    
        if(login_status == false){
            System.out.printf("\nTo do this, you must first log into %s account.",username);
        }

        else{
            System.out.printf("\nYou blocked: %s",account.getUsername());
            blocked_users.add(account); 
            blocked_users_number++;
            this.unfollow(account);
            actions.add("You blocked " + account.getUsername());
        }
    }

    /**
     * Unblocks the given account
     *
     * @param account the account to unblock
     */
    public void unblockUser(Account account){

        if(login_status == false){
            System.out.printf("\nTo do this, you must first log into %s account.",username);
        }

        else{
        
            for(int i=0 ; i<blocked_users_number; i++){

                if(blocked_users.get(i).getAccountId() == account.getAccountId()){
                    blocked_users.remove(i);
                    blocked_users_number--;
                    System.out.printf("\nYou are unblocking %s account",account.getUsername());
                    actions.add("You unblocked " + account.getUsername());
                    return;
                }
            }
        }

        System.out.printf("\nYou have not blocked this account.");
    }

    
    /**
     * Prints the record of the actions made in the account on the screen
     */
    public void showActions(){

        if(login_status == false){
            System.out.printf("\nTo do this, you must first log into %s account.",username);
        }

        else{
            System.out.printf("Actions of %s account",username);
            for(int i=0 ; i<actions.size() ; i++){

                System.out.printf("\n%s",actions.get(i));
            }
        }
    }

    /**
     * Allows adding elements to an actions object from another class
     * @param content  The element to be added to the Actions object
     */
    public void addActions(String content){
       actions.add(content);
    }

}
