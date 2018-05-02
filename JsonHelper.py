import jsonpickle


class JsonHelper:
    @staticmethod
    def object_as_json_to_file(filepath: str, object_to_store):
        if jsonpickle.load_backend('simplejson'):
            jsonpickle.set_preferred_backend('simplejson')
            jsonpickle.set_encoder_options('simplejson', sort_keys=True, indent=4)
        else:
            print('Couldn\'t load simplejson')
        with open(filepath, 'w') as outfile:
            json_output = jsonpickle.encode(object_to_store, unpicklable=False)
            outfile.write(json_output)