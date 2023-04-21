/* eslint-disable prettier/prettier */
import React from 'react';
import { useState } from 'react';
import { Pressable, StyleSheet, Text, TextInput, View } from 'react-native';
import DatePicker from 'react-native-date-picker';
import { useSelector, useDispatch } from 'react-redux';
import { setJob, addJob } from '../src/actions/jobActions';
import Job from '../src/types/job';

function DetailScreen({ navigation }: { navigation: object }): JSX.Element {
  const [open, setOpen] = useState(false);

  const state = useSelector(state => state?.jobReducer);
  const dispatch = useDispatch();

  const handleFinsihed = (jobInsert: Job) => {
    dispatch(addJob(jobInsert));
    navigation?.navigate('Home');
  };

  return (
    <View style={[styles.detailPage]}>
      <View style={styles.inputWrap}>
        <Text style={[styles.title]}>Title </Text>
        <TextInput
          editable
          placeholder="Title"
          value={state?.job?.title}
          onChangeText={text => {
            dispatch(setJob({ ...state?.job, title: text }));
          }}
          style={[styles.textInput]}
        />
      </View>
      <View style={styles.inputWrap}>
        <Text style={[styles.title]}>Description </Text>
        <TextInput
          editable
          placeholder="Description"
          value={state?.job?.description}
          onChangeText={text => {
            dispatch(setJob({ ...state?.job, description: text }));
          }}
          style={[styles.textInput]}
        />
      </View>

      <View style={styles.inputWrap}>
        <Pressable onPress={() => setOpen(true)}>
          <Text style={[styles.title, styles.selectDateBtn]}>Select date </Text>
        </Pressable>
        <DatePicker
          modal
          open={open}
          date={state?.job?.date}
          onConfirm={dateSelected => {
            dispatch(setJob({ ...state?.job, date: dateSelected}));
            setOpen(false);
          }}
          onCancel={() => setOpen(false)}
        />
      </View>

      <View style={[styles.inputWrap, styles.finishedBtn]}>
        <Pressable onPress={() => handleFinsihed(state?.job)}>
          <Text style={[styles.title, styles.finishedBtnText]}>Finished</Text>
        </Pressable>
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  finishedBtn: {
    marginTop: 0,
  },
  finishedBtnText: {
    textAlign: 'center',
    color: '#34808c',
    fontSize: 22,
  },
  selectDateBtn: {
    height: 50,
    backgroundColor: '#57ccff',
    marginTop: 15,

    lineHeight: 50,
    textAlign: 'center',
    color: '#fff',

    borderRadius: 4,
  },
  inputWrap: {
    margin: 15,

    display: 'flex',
    flexDirection: 'column',
  },
  textInput: {
    padding: 10,
    marginTop: 5,

    fontSize: 18,
    color: '#999',

    borderColor: 'gray',
    borderRadius: 4,
    borderWidth: 1,
  },
  detailPage: {
    height: '100%',
    width: '100%',
    position: 'relative',
  },
  title: {
    fontSize: 24,
    color: '#666',
  },
});

export default DetailScreen;

