// #include <bits/stdc++.h>
// using namespace std;

// // 방->대화방->
// class Message
// {
// public:
//     void success()
//     {
//         cout << "작업을 완료했습니다." << endl;
//     }
//     void no_authority()
//     {
//         cout << "권한이 없습니다." << endl;
//     }
//     void not_include()
//     {
//         cout << "방의 일원이 아닙니다." << endl;
//     }
//     void aready_include()
//     {
//         cout << "이미 참여중입니다." << endl;
//     }
//     void password_error()
//     {
//         cout << "패스워드가 틀립니다." << endl;
//     }
//     void only_one_eror()
//     {
//         cout << "하나의 방에만 참여가능합니다.." << endl;
//     }
//     void only_one_room()
//     {
//         cout << "하나의 방에만 참여가능합니다.." << endl;
//     }
//     void enter_room(string userName, string room)
//     {
//         cout << userName + "님이" + room + "방에 참여했습니다." << endl;
//     }
//     void enter_chat_room(string userName, string chatroom)
//     {
//         cout << chatroom + userName + "님이 " + chatroom + "채팅방에 참여했습니다." << endl;
//     }
// } message;
// class user;
// class ChatRoom;
// class Room;
// class User
// {
//     string userName;
//     Room room; //참여하고있는방
// };
// class ChatRoom
// {
//     string name;
//     User *owner;
//     string message;
//     set<User *> users;
//     set<pair<User *, bool>> role; //말할 수 있는권리
// public:
//     ChatRoom(User *owner, User *user, string name)
//     {
//         this->owner = owner;
//         if (user != owner)
//             users.insert(user);
//         this->name = name;
//     }
// };
// class Room
// {
//     User *owner;
//     string name;
//     set<User *> users;
//     set<ChatRoom *> chatRooms;
//     bool Secret = false;
//     string password;
//     Room(User *owner, string name)
//     {
//         this->owner = owner;
//         this->name = name;
//     }
//     void makeChatRoom(User *user, string name)
//     {
//         if (owner != user && users.find(user) == users.end())
//             message.not_include();
//         else
//             ChatRoom *chatroom = new ChatRoom(this->owner, user, name);
//     }
//     void makeSecret(User *owner, bool how)
//     {
//         if (this->owner == owner)
//         {
//             message.success();
//             Secret = how;
//         }
//         else
//             message.no_authority();
//     }
//     void enterRoom(User *user, string password = "")
//     {
//         if (users.find(user) != users.end())
//             message.aready_include();
//         if (this->Secret == true)
//         {
//             if (this->password != password)
//                 message.password_error();
//         }
//         else
//         {
//             message.enter_room(user->userName, name);
//             users.insert(user);
//         }
//     }
//     // void leaveOne(User *owner, User *who)
//     // {
//     //     if (!this->owner != owner)
//     //         message.no_authority();
//     //     else
//     //     {
//     //         users.erase(owner);
//     //         for (auto &chatroom : chatRooms)
//     //         {
//     //             chatroom.
//     //         }
//     //     }
//     // }
// };
// int main()
// {
//     return 0;
// }