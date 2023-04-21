import React from 'react';
import { StyleSheet, Text, View, Image } from 'react-native';

function StudentCard({
  id = 'No id',
  name = 'No name',
  description = 'No description',
  avatarLink = 'https://chungcuterraflora.com/wp-content/uploads/2022/10/hinh-chibi-cute-de-ve-4.jpg',
  overrideStyle = {},
}: {
  id?: string;
  name?: string;
  description?: string;
  avatarLink?: string;
  overrideStyle?: object;
}): JSX.Element {
  return (
    <View style={[styles.studentCard, overrideStyle]}>
      <Image
        style={styles.studentAvatar}
        source={{
          uri: avatarLink,
        }}
      />
      <View style={styles.studentInfo}>
        <Text style={[styles.text, styles.studentId]}>Student Id: {id}</Text>
        <Text style={[styles.text, styles.studentName]}>
          Student Name: {name}
        </Text>
        <Text style={[styles.text, styles.description]}>
          Description: {description}
        </Text>
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  studentCard: {
    display: 'flex',
    flexDirection: 'row',
    backgroundColor: '#92ccff',
    borderRadius: 10,
    minWidth: 300,
    padding: 10,
    maxWidth: '100%',
    maxHeight: '100%'
  },
  studentAvatar: {
    borderRadius: 10,
    width: 120,
    height: 120,
  },
  studentInfo: {
    display: 'flex',
    flexDirection: 'column',
    justifyContent: 'space-around',
    marginLeft: 20,
  },
  text: {
    fontSize: 20,
    textWrap: 'wrap',
    maxWidth: 240,
    lineHeight: 25,
  },
  studentName: {},
  studentId: {},
  description: {},
});

export default StudentCard;
