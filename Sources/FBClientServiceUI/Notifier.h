/**
* Facebook Internet Explorer Toolbar Software License 
* Copyright (c) 2009 Facebook, Inc. 
*
* Permission is hereby granted, free of charge, to any person or organization
* obtaining a copy of the software and accompanying documentation covered by
* this license (which, together with any graphical images included with such
* software, are collectively referred to below as the "Software") to (a) use,
* reproduce, display, distribute, execute, and transmit the Software, (b)
* prepare derivative works of the Software (excluding any graphical images
* included with the Software, which may not be modified or altered), and (c)
* permit third-parties to whom the Software is furnished to do so, all
* subject to the following:
*
* The copyright notices in the Software and this entire statement, including
* the above license grant, this restriction and the following disclaimer,
* must be included in all copies of the Software, in whole or in part, and
* all derivative works of the Software, unless such copies or derivative
* works are solely in the form of machine-executable object code generated by
* a source language processor.  
*
* Facebook, Inc. retains ownership of the Software and all associated
* intellectual property rights.  All rights not expressly granted in this
* license are reserved by Facebook, Inc.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
* SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
* FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
* DEALINGS IN THE SOFTWARE.
*/

#ifndef NOTIFIER_H
#define NOTIFIER_H

#include "../data/ServiceData.h"
#include "../data/NotificationsData.h"
#include "../data/ChangesTypes.h"

#include "../util/StringUtils.h"

namespace facebook {

/**
 * class Notifier
 *
 * Creates notification popups based on 
 * different notification types
 *
 * @See NotificationsData.h
 */

class Notifier{

  //constriction/destruction
public:
  Notifier() {};
  ~Notifier() {};

  //public methods
public:

  /**
   * Shows notification popup, when user own data changed
   *
   * @param changeID - id of change event (by ref)
   * @param sourceData - changed data (by ref)
   */
  static void showSelfNotification(const DataChangeEvents& changeID, 
                                   const ServiceData& sourceData);

  /**
   * Shows notification popup, when user's friends data changed
   *
   * @param changeID - id of change event (by ref)
   * @param friendsIds - ids of friends whose data changed(by ref)
   * @param sourceData - changed data (by ref)
   */
  static void showFriendsChangePopup(const DataChangeEvents& changeID,
                                     const FriendsIDs& friendsIds, 
                                     const ServiceData& sourceData);

  /**
   * Shows notification popup, when user's friends albums changed
   *
   * @param changeID - id of change event (by ref)
   * @param albumsIds - ids of changed albums(by ref)
   * @param sourceData - changed data (by ref)
   */
  static void Notifier::showAlbumsChangePopup(const DataChangeEvents& changeID,
                                                     const AlbumsIDs& albumsIds, 
                                                     const ServiceData& sourceData);
 private:

  /**
   *
   * notifyMyStatus - show notification when user changed status
   *
   * @param text - status text
   *
   * @return void
   */
  static void notifyMyStatus(const String& text, 
                                 const String& id, 
                                 const String& userPic);

  /**
   *
   * notifyMessage - show notification when user received message
   *
   * @param msgCount - count of messages in inbox
   *
   * @return void
   */
  static void notifyMessage(long msgCount);

  /**
   *
   * notifyPoke - show notification when I am poked
   *
   * @param msgCount - count of messages in inbox
   *
   * @return void
   */
  static void notifyPoke(long pokeCount);


  /**
   *
   * notifyPoke - show notification when someone want to add me to his/her friendlist
   *
   * @param username     - name of the requested user
   * @param userpicPath  - requested user path
   *
   * @return void
   */

   static void notifyFriendsRequest(const String& username, 
                                    const String& userpicPath);


  /**
   *
   * notifyAlbums - show notification when someone added/updated albums
   *
   * @param album       - album name
   * @param albumsOwner - albums owner
   * @param isExist     - is album exist
   * @param link        - link
   * @param changeID    - change id
   * @return void
   */
   static void Notifier::notifyAlbums(const String& album, 
                                             const String& albumOwner, 
                                             const String& link, 
                                             const DataChangeEvents& changeID);

  /**
   *
   * notifyWall - show notification when someone wrote on my wall
   *
   * @return void
   */
  static void notifyWall(const String& userID);

  /**
   *
   * notifySoMyFriend - show notification when someone become my friend
   *
   * @param  friendName   - friend name 
   * @param  friendID     - id of user which become my friend
   * 
   * @return void
   */
  static void notifySoMyFriend(const String& friendName, 
                               const String& friendID, 
                               const String& friendPic);

  /**
   *
   * notifyFriendStatusChanged - show notification when friend`s status changed
   *
   * @param  friendName   - friend name 
   * @param  friendID     - id of user which become my friend
   * @param  status       - status 
   * @return void
   */
  static void notifyFriendStatusChanged(const String& friendName, 
                                        const String& friendID, 
                                        const String& status, 
                                        const String& friendPic);

  /**
   *
   * notifyFriendWallSoWrote - show notification when someone wrote on friend`s wall
   *
   * @param  friendName   - friend name 
   * @param  friendID     - id of user which become my friend
   * @return void
   */
  static void notifyFriendWallSoWrote(const String& friendName, 
                                      const String& friendID,
                                      const String& friendPic);


  /**
   *
   * notifyFriendWroteNote - show notification when friend a note
   *
   * @param  friendName   - friend name 
   * @param  friendID     - id of user which become my friend
   * @return void
   */
  static void notifyFriendWroteNote(const String& friendName, 
                                    const String& friendID,
                                    const String& friendPic);


  /**
   *
   * notifyFriendUpdateProfile - show notification when friend update his/her status
   *
   * @param  friendName   - friend name 
   * @param  friendID     - id of user which become my friend
   * @return void
   */
  static void notifyFriendUpdateProfile(const String& friendName, 
                                        const String& friendID,
                                        const String& friendPic);


protected:

  /**
   *
   * getSquarePicUrl - get small pic. In case of 
   *                  small picture return default image
   *
   * @param userData: check 
   *
   * @return url
   */
  static String getSquarePicUrl(const UserData& userData);
};

} // !namespace facebook

#endif // NOTIFIER_H