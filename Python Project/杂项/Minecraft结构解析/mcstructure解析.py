import nbtlib
import json


def nbt_to_json(tag):
    """将NBT标签转换为JSON对象"""
    if isinstance(tag, nbtlib.tag.Compound):
        return {k: nbt_to_json(v) for k, v in tag.items()}
    elif isinstance(tag, (nbtlib.tag.ByteArray, nbtlib.tag.IntArray, nbtlib.tag.LongArray)):
        return list(tag)
    elif isinstance(tag, (nbtlib.tag.String, nbtlib.tag.Float, nbtlib.tag.Int, nbtlib.tag.Long,
                          nbtlib.tag.Short, nbtlib.tag.Byte, nbtlib.tag.Double)):
        # 对于这些类型，直接返回它们的值（已经是Python的原生类型）
        return tag
    elif isinstance(tag, nbtlib.tag.List):
        # 对于列表类型，递归处理列表中的每个元素
        return [nbt_to_json(i) for i in tag]
    else:
        raise NotImplementedError(f"Unsupported tag type: {type(tag)}")


def read_nbt_file_and_save_json(nbt_filename, json_filename):
    # 加载NBT文件
    root_tag = nbtlib.load(nbt_filename)  # 直接传递文件名，而不是文件对象

    # 转换为JSON对象
    json_obj = nbt_to_json(root_tag)

    # 将JSON对象保存到文件
    with open(json_filename, 'w', encoding='utf-8') as json_file:
        json.dump(json_obj, json_file, ensure_ascii=False, indent=4, sort_keys=True)

    # 调用函数，传入.nbt文件名和要保存的.json文件名


read_nbt_file_and_save_json('snow_relics.nbt', 'output_file.json')
