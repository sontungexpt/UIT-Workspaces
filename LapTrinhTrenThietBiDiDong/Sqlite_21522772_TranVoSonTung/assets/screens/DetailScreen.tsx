import React from 'react';
import { StyleSheet, View } from 'react-native';
import ClassCard from '../components/ClassCard';
import StudentCard from '../components/StudentCard';

function DetailScreen(): JSX.Element {
  return (
    <View style={[styles.detailPage]}>
      <ClassCard overrideStyle={styles.classCard} />
      <StudentCard overrideStyle={styles.studentCard} />
    </View>
  );
}

const styles = StyleSheet.create({
  detailPage: {
    display: 'flex',
    alignItems: 'center',
    height: '100%',
    width: '100%',
  },
  classCard: {
    width: '100%',
    padding: 10,
    borderRadius: 10,
    margin: 0,
  },
  studentCard: {
    marginTop: 20,
  },
});

export default DetailScreen;
