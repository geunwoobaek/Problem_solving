package cupist;
import java.util.Scanner;

import jdk.nashorn.internal.parser.JSONParser;


public class Problem1 {
    static String maleJsonString = 
    "{\"Male\":[{\"name\":\"근우\",\"birthday\":\"1987-06-22\",\"height\":\"187\",\"job\":\"배우\",\"location\":\"126.9683104,37.344701\",\"hobbies\":\" [{\"독서\", \"영화\", \"축구\"}]\"}]}";

        
    void input(boolean isMale) {
        JSONParser jsonParser = new JSONParser();

        String total;
        String name;
		int age;
		double height;
        Scanner sc = new Scanner(System.in);
        
    }

    public static void main(String[] args) {

    }
}
create table chat_room (id bigint not null, created_date timestamp, is_user1exists boolean not null, is_user2exists boolean not null, user1_id bigint, user2_id bigint, primary key (id))
create table good_apply (id bigint not null, apply_date timestamp, is_accepted boolean, entity1_id bigint, entity2_id bigint, primary key (id))
create table hobby (id bigint not null, hobby_name varchar(255), primary key (id))
create table user (id bigint not null, birthday date, gender varchar(255), name varchar(255), nick_name varchar(255), primary key (id))
create table user_hobby (id bigint not null, hobby_id bigint, user_id bigint, primary key (id))
alter table chat_room add constraint FK88tc5678gtd1143e3lkkex6h foreign key (user1_id) references user
alter table chat_room add constraint FK3u4jrd2g2oqey0b0ojy8pgve2 foreign key (user2_id) references user
alter table good_apply add constraint FK5t97laaihwt8evvsy3rlgg555 foreign key (entity1_id) references user
alter table good_apply add constraint FKuf7xrsr06mnop8usil0yuags foreign key (entity2_id) references user
alter table user_hobby add constraint FKg5dvw1ny1qp6j37gkueih2md0 foreign key (hobby_id) references hobby
alter table user_hobby add constraint FKbb99gkcqchq4w3hmqnugmcwhc foreign key (user_id) references user
